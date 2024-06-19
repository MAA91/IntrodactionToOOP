//Fraction.h
#pragma once
#include"stdafx.h"

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction();
	explicit Fraction(int numerator);
	Fraction(double value);
	Fraction(int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	int get_denominator()const;
	int get_numerator()const;
	void set_denominator(int denominator);
	void set_numerator(int numerator);
	void print()const;

	Fraction& operator= (const Fraction& other);
	Fraction& operator++();
	Fraction& operator--();
	Fraction operator++(int);
	Fraction operator--(int);
	void operator += (const Fraction& right);
	void operator -= (const Fraction& right);
	void operator *= (const Fraction& right);
	void operator /= (const Fraction& right);

	void reduction();
	double decimal_form()const;
	int integer_part()const;
	double fractional_part()const;
	int integer_rounding()const;

	explicit operator int();
	operator double();
};

Fraction operator + (const Fraction& left, int right);
Fraction operator + (int left, const Fraction& right);
Fraction operator + (const Fraction& left, const Fraction& right);
Fraction operator - (const Fraction& left, int right);
Fraction operator - (int left, const Fraction& right);
Fraction operator - (const Fraction& left, const Fraction& right);
Fraction operator * (const Fraction& left, int right);
Fraction operator * (int left, const Fraction& right);
Fraction operator * (const Fraction& left, const Fraction& right);
Fraction operator / (const Fraction& left, int right);
Fraction operator / (int left, const Fraction& right);
Fraction operator / (const Fraction& left, const Fraction& right);

bool operator== (const Fraction& left, const Fraction& right);
bool operator!= (const Fraction& left, const Fraction& right);
bool operator> (const Fraction& left, const Fraction& right);
bool operator>= (const Fraction& left, const Fraction& right);
bool operator< (const Fraction& left, const Fraction& right);
bool operator<= (const Fraction& left, const Fraction& right);

std::ostream& operator<< (std::ostream& os, const Fraction& obj);
std::istream& operator>> (std::istream& is, Fraction& obj);