#include <rational/rational.hpp>

#include <iostream>



Rational::Rational() { 
    num_ = 0;
    denom_ = 1;
}

Rational::Rational(const int32_t value) noexcept{
    num_ = value;
    denom_ = 1;
}


Rational::Rational(int32_t numIn, int32_t denumIn) {
    if (denumIn == 0) {
        throw std::invalid_argument("Divide by zero exeption");
    }
    if (denumIn < 0) {
        numIn *= -1;
        denumIn *= -1;
    }
    num_ = numIn;
    denom_ = denumIn;
    redusing();
}

Rational& Rational::operator=(const Rational& rhs) {
    num_ = rhs.num_;
    denom_ = rhs.denom_;
    return *this;
}


Rational Rational::operator+(const Rational& rhs) const {
    if ((num_ * rhs.denom_ + rhs.num_ * denom_) == 0) {
        Rational r(0, 1);
        return r;
    }
    Rational r(num_ * rhs.denom_ + rhs.num_ * denom_, rhs.denom_ * denom_);
    return normalize(r);
}

Rational Rational::operator+() const {
    return *this;
}

Rational Rational::operator-(const Rational& rhs) const {
    if ((num_ * rhs.denom_ - rhs.num_ * denom_) == 0) {
        Rational r(0, 1);
        return r;
    }
    Rational r(num_ * rhs.denom_ - rhs.num_ * denom_, rhs.denom_ * denom_);
    return normalize(r);
}
Rational Rational::operator-() const {
    Rational r(-num_, denom_);
    return r;
}
Rational Rational::operator*(const Rational& rhs) const {
    if (num_ * rhs.num_ == 0) {
        Rational r(0, 1);
        return r;
    }
    Rational r(num_ * rhs.num_, denom_ * rhs.denom_);
    return normalize(r);
}
Rational Rational::operator/(const Rational& rhs) const {
    if (num_ * rhs.denom_ == 0) {
        Rational r(0, 1);
        return r;
    }
    Rational r(num_ * rhs.denom_, denom_ * rhs.num_);
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
Rational& Rational::operator%=(const Rational& rhs) {
    int32_t mult = rhs.denom_ / gcd(denom_, rhs.denom_);
    num_ *= mult;
    denom_ *= mult;
    num_ %= denom_ / rhs.denom_ * rhs.num_;
    redusing();
    return *this;
}




bool Rational::operator<(const Rational& rhs) const {
    return num_ * rhs.denom_ < rhs.num_ * denom_;
}
bool Rational::operator>(const Rational& rhs) const {
    return num_ * rhs.denom_ > rhs.num_ * denom_;
}
bool Rational::operator<=(const Rational& rhs) const {
    return !(*this > rhs);
}
bool Rational::operator>=(const Rational& rhs) const {
    return !(*this < rhs);
}
bool Rational::operator==(const Rational& rhs) const {
    return num_ == rhs.num_ && denom_ == rhs.denom_;
}
bool Rational::operator!=(const Rational& rhs) const {
    return !(*this == rhs);
}


double Rational::toDouble() const {
    return num_ / (double)denom_;
}

Rational pow(Rational tmp) {
    Rational temp = tmp * tmp;
    return temp;
}

void Rational::redusing() {
    if (num_ < 0) {
        int32_t g = gcd(-num_, denom_);
    }
    else {
        int32_t g = gcd(num_, denom_);
    }
}

int32_t Rational::gcd(int32_t num_, int32_t denom_) const {
    if (num_ < denom_) {
        std::swap(num_, denom_);
    }
    num_ %= denom_;
    if (num_ == 0) {
        return denom_;
    }
    else {
        return gcd(num_, denom_);
    }
}


Rational Rational::normalize(Rational& rhs) const {
    int32_t a, b;
    a = std::abs(rhs.num_); 
    b = std::abs(rhs.denom_);
    while(b){
        a %= b;
        std::swap(a, b);
    }
    return Rational(rhs.num_ / a, rhs.denom_ / a);
}



std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
    ostrm << num_ << separator << denom_;
    return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm)
{
    char sym('-');
    while (std::isspace(istrm.peek())) {
        sym = istrm.get();
    }
    int32_t numInp_(0);
    int32_t denomInp_(0);
    sym = '-' ;
    bool isNeg(false);
    if (istrm.peek() == '-') {
        isNeg = true;
        sym = istrm.get();
    }

    while (std::isdigit(istrm.peek())) {
        sym = istrm.get();
        numInp_ *= 10;
        numInp_ += static_cast<int>(sym - '0');
    }
    if (sym == '-') {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }

    if (istrm.peek() != '/') {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    sym = istrm.get();

    while (std::isdigit(istrm.peek())) {
        sym = istrm.get();
        denomInp_ *= 10;
        denomInp_ += static_cast<int>(sym - '0');
    }
    if (sym == '/') {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    
    if (istrm.good() || istrm.eof()) {
        if (denomInp_ == 0) {
            istrm.setstate(std::ios_base::failbit);
            return istrm;
        }
        num_ = numInp_;
        denom_ = denomInp_;
        if (isNeg) {
            num_ *= -1;
        }
        redusing();
    }
    return istrm;
}
