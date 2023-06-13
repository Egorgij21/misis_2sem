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
    Rational(const int32_t num_input) noexcept;
    Rational(const Rational&) = default;
    Rational(Rational&&) = default;
    Rational(const int32_t num_input, const int32_t denom_input);
    ~Rational() = default;

    Rational& operator=(const Rational& rhs);
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);
    Rational& operator%=(const Rational& rhs);

    std::ostream& WriteTo(std::ostream&) const noexcept;
	std::istream& ReadFrom(std::istream&);

    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);

    bool IsPositive() const;
    bool IsZero() const;
    bool IsNegative() const;


    double toDouble() const;
private:
    void redusing();
    int32_t gcd(int32_t num, int32_t denom) const;
    Rational normalize(Rational&) const;
};


Rational operator+(const Rational& rhs);
Rational operator-(const Rational& rhs);

Rational operator+(Rational lhs, const Rational& rhs);
Rational operator-(Rational lhs, const Rational& rhs);
Rational operator*(Rational lhs, const Rational& rhs);
Rational operator/(Rational lhs, const Rational& rhs);


Rational pow(Rational Rat, int32_t power);


Rational operator%(const Rational& lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);


#endif