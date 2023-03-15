#pragma once

#pragma once

#ifndef RATIONAL_HPP
#define RATIONAL_HPP



#include<iosfwd>



class Rational{

int32_t num = 0;
int32_t denum = 1;

public:
    Rational();
    Rational(const int32_t);
    Rational(const int32_t num, const int32_t denum);
    ~Rational() = default;



    std::ostream& writeTo(std::ostream&) const;
	std::istream& readFrom(std::istream&);



    Rational& operator=(const Rational&);
    Rational& operator=(const int32_t&);



    Rational operator+(const Rational&) const;
    Rational operator-(const Rational&) const;
    Rational operator-() const;
    Rational operator*(const Rational&) const;
    Rational operator/(const Rational&) const;
    Rational operator++();
    Rational operator++(int);

	Rational operator--();
    Rational operator--(int);




    Rational& operator+=(const Rational&);
    Rational& operator-=(const Rational&);
    Rational& operator*=(const Rational&);
    Rational& operator/=(const Rational&);



    bool operator<(const Rational&) const;
    bool operator>(const Rational&) const;
    bool operator<=(const Rational&) const;
    bool operator>=(const Rational&) const;
    bool operator==(const Rational&) const;
    bool operator!=(const Rational&) const;


    double toDouble() const;
private:
    void reduce();
    int32_t gcd(int32_t num, int32_t denum) const;
    Rational normalize(Rational&) const;
};

Rational pow(Rational);

#endif