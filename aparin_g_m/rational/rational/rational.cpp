#include "rational/rational.h"

#include <iostream>



Rational::Rational() { 
    num = 0;
    denum = 1;
}

Rational::Rational(const int32_t value) {
    num = value;
    denum = 1;
}


Rational::Rational(int32_t numIn, int32_t denumIn) {
    if (denumIn == 0) {
        throw std::invalid_argument("Divide by zero exeption");
    }
    if (denumIn < 0) {
        numIn *= -1;
        denumIn *= -1;
    }
    num = numIn;
    denum = denumIn;
    reduce();
}

Rational& Rational::operator=(const Rational& rhs) {
    num = rhs.num;
    denum = rhs.denum;
    return *this;
}

Rational& Rational::operator=(const int32_t& value) {
    num = value;
    denum = 1;
    return *this;
}

Rational Rational::operator+(const Rational& rhs) const {
    if ((num * rhs.denum + rhs.num * denum) == 0) {
        Rational r(0, 1);
        return r;
    }
    Rational r(num * rhs.denum + rhs.num * denum, rhs.denum * denum);
    return normalize(r);
}


Rational Rational::operator-(const Rational& rhs) const {
    if ((num * rhs.denum - rhs.num * denum) == 0) {
        Rational r(0, 1);
        return r;
    }
    Rational r(num * rhs.denum - rhs.num * denum, rhs.denum * denum);
    return normalize(r);
}
Rational Rational::operator-() const {
    Rational r(-num, denum);
    return r;
}
Rational Rational::operator*(const Rational& rhs) const {
    if (num * rhs.num == 0) {
        Rational r(0, 1);
        return r;
    }
    Rational r(num * rhs.num, denum * rhs.denum);
    return normalize(r);
}
Rational Rational::operator/(const Rational& rhs) const {
    if (num * rhs.denum == 0) {
        Rational r(0, 1);
        return r;
    }
    Rational r(num * rhs.denum, denum * rhs.num);
    return normalize(r);
}
Rational Rational::operator++() { // ++x
    *this = *this + 1;
    return *this;
}
Rational Rational::operator++(int) { // x++
    Rational copy = *this;
    *this = *this + 1;
    return copy;
}

Rational Rational::operator--() {
    *this = *this - 1;
    return *this;
}
Rational Rational::operator--(int) {
    Rational copy = *this;
    *this = *this - 1;
    return copy;
}




Rational& Rational::operator+=(const Rational& rhs) {
    *this = *this + rhs;
    return *this;
}
Rational& Rational::operator-=(const Rational& rhs) {
    *this = *this - rhs;
    return *this;
}
Rational& Rational::operator*=(const Rational& rhs) {
    *this = *this * rhs;
    return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
    *this = *this / rhs;
    return *this;
}




bool Rational::operator<(const Rational& rhs) const {
    return num * rhs.denum < rhs.num * denum;
}
bool Rational::operator>(const Rational& rhs) const {
    return num * rhs.denum > rhs.num * denum;
}
bool Rational::operator<=(const Rational& rhs) const {
    return !(*this > rhs);
}
bool Rational::operator>=(const Rational& rhs) const {
    return !(*this < rhs);
}
bool Rational::operator==(const Rational& rhs) const {
    return num == rhs.num && denum == rhs.denum;
}
bool Rational::operator!=(const Rational& rhs) const {
    return !(*this == rhs);
}


double Rational::toDouble() const {
    return num / (double)denum;
}
Rational& Rational::sqrt() const {
    Rational r (num * num, denum * denum);
    return r;
}
void Rational::reduce() {
    if (num < 0) {
        int32_t g = gcd(-num, denum);
    }
    else {
        int32_t g = gcd(num, denum);
    }
}

int32_t Rational::gcd(int32_t num, int32_t denum) const {
    if (num < denum) {
        std::swap(num, denum);
    }
    num %= denum;
    if (num == 0) {
        return denum;
    }
    else {
        return gcd(num, denum);
    }
}


Rational Rational::normalize(Rational& rhs) const {
    int32_t a, b;
    a = std::abs(rhs.num); 
    b = std::abs(rhs.denum);
    while(b){
        a %= b;
        std::swap(a, b);
    }
    return Rational(rhs.num / a, rhs.denum / a);
}



std::ostream& Rational::writeTo(std::ostream& ostrm) const {
	ostrm << num << "/" << denum;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
	int32_t tmp_num(0), tmp_denum(0);
	char symb(0);
	std::cin >> tmp_num >> symb >> tmp_denum;
	if(istrm.good()){
		if (symb == '/'){
			num = tmp_num;
			denum = tmp_denum;
            if (num != 0) {
			    gcd(num, denum);
            }
		}
		else{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
