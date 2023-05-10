#pragma once


#ifndef RATIONAL_HPP
#define RATIONAL_HPP



#include<iosfwd>



class Rational{
public:

int32_t num_ = 0;
int32_t denom_ = 1;
static const char separator = '/' ;

public:
    Rational();
    Rational(const int32_t) noexcept;
    Rational(const Rational&) = default;
    Rational(Rational&&) = default;
    Rational(const int32_t num_input, const int32_t denom_input);
    ~Rational() = default;



    std::ostream& WriteTo(std::ostream&) const noexcept;
	std::istream& ReadFrom(std::istream&);



    Rational& operator=(const Rational&);


    Rational operator+(const Rational&) const;
    Rational operator+() const;
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
    Rational& operator%=(const Rational&);


    bool operator<(const Rational&) const;
    bool operator>(const Rational&) const;
    bool operator<=(const Rational&) const;
    bool operator>=(const Rational&) const;
    bool operator==(const Rational&) const;
    bool operator!=(const Rational&) const;


    double toDouble() const;
private:
    void redusing();
    int32_t gcd(int32_t num, int32_t denom) const;
    Rational normalize(Rational&) const;
};

Rational pow(Rational);

#endif