//Fraction.cpp
#include"Fraction.h"

Fraction::Fraction()
{
	numerator = denominator = 1;
	cout << "DefaultConstractor:\t" << this << endl;
}
Fraction::Fraction(int numerator)
{
	this->numerator = numerator;
	this->denominator = 1;
	cout << "1ArgConstractorInt:\t" << this << endl;
}
Fraction::Fraction(double value)
{
	numerator = 0;
	value += 10e-11;
	denominator = 1;
	int size_integer = 0;
	for (; !(value >= pow(10, size_integer - 1) and value < pow(10, size_integer)); size_integer++);
	numerator = value;
	value -= (int)value;
	value *= 10;
	for (int i = 0; i < 9 - size_integer; i++)
	{
		denominator *= 10;
		numerator *= 10;
		numerator += value;
		value -= (int)value;
		value *= 10;
	}
	this->reduction();
	cout << "1ArgConstractorDouble:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	cout << "Constractor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstractor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destractor:\t" << this << endl;
}

int Fraction::get_denominator()const
{
	return denominator;
}
int Fraction::get_numerator()const
{
	return numerator;
}
void Fraction::set_denominator(int denominator)
{
	this->denominator = denominator;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::print()const
{
	if (numerator == 0)
		cout << 0;
	else if (denominator == 1)
		cout << numerator;
	else
		cout << numerator << "/" << denominator;
	cout << endl;
}

Fraction& Fraction::operator= (const Fraction& other)
{
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssigment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator++()
{
	numerator += denominator;
	return *this;
}
Fraction& Fraction::operator--()
{
	numerator -= denominator;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	numerator += denominator;
	return old;
}
Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	numerator -= denominator;
	return old;
}
void Fraction::operator += (const Fraction& right)
{
	numerator *= right.denominator;
	numerator += (right.numerator * denominator);
	denominator *= right.denominator;
	this->reduction();
}
void Fraction::operator -= (const Fraction& right)
{
	numerator *= right.denominator;
	numerator -= (right.numerator * denominator);
	denominator *= right.denominator;
	this->reduction();
}
void Fraction::operator *= (const Fraction& right)
{
	numerator *= right.numerator;
	denominator *= right.denominator;
	this->reduction();
}
void Fraction::operator /= (const Fraction& right)
{
	numerator *= right.denominator;
	denominator *= right.numerator;
	this->reduction();
}

void Fraction::reduction()
{
	for (int i = 2; i <= abs(numerator) or i <= abs(denominator);)
		if (numerator % i == 0 and denominator % i == 0)
		{
			numerator /= i;
			denominator /= i;
		}
		else i++;
	if (denominator < 0)
	{
		numerator *= (-1);
		denominator *= (-1);
	}
}
double Fraction::decimal_form()const
{
	return (double)numerator / denominator;
}
int Fraction::integer_part()const
{
	return numerator / denominator;
}
double Fraction::fractional_part()const
{
	return this->decimal_form() - this->integer_part();
}
int Fraction::integer_rounding()const
{
	if (this->fractional_part() < 0.5)
		return this->integer_part();
	return this->integer_part() + 1;
}

Fraction::operator int()
{
	return this->integer_part();
}
Fraction::operator double()
{
	return this->decimal_form();
}

//Functions
Fraction operator + (const Fraction& left, int right)
{
	return Fraction
	(
		left.get_numerator() + right * left.get_denominator(),
		left.get_denominator()
	);
}
Fraction operator + (int left, const Fraction& right)
{
	return Fraction
	(
		right.get_numerator() + left * right.get_denominator(),
		right.get_denominator()
	);
}
Fraction operator + (const Fraction& left, const Fraction& right)
{
	Fraction result
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		right.get_denominator() * left.get_denominator()
	);
	result.reduction();
	return result;
}
Fraction operator - (const Fraction& left, int right)
{
	return Fraction
	(
		left.get_numerator() - right * left.get_denominator(),
		left.get_denominator()
	);
}
Fraction operator - (int left, const Fraction& right)
{
	return Fraction
	(
		left * right.get_denominator() - right.get_numerator(),
		right.get_denominator()
	);
}
Fraction operator - (const Fraction& left, const Fraction& right)
{
	Fraction result
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		right.get_denominator() * left.get_denominator()
	);
	result.reduction();
	return result;
}
Fraction operator * (const Fraction& left, int right)
{
	Fraction result
	(
		left.get_numerator() * right,
		left.get_denominator()
	);
	result.reduction();
	return result;
}
Fraction operator * (int left, const Fraction& right)
{
	Fraction result
	(
		right.get_numerator() * left,
		right.get_denominator()
	);
	result.reduction();
	return result;
}
Fraction operator * (const Fraction& left, const Fraction& right)
{
	Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		right.get_denominator() * left.get_denominator()
	);
	result.reduction();
	return result;
}
Fraction operator / (const Fraction& left, int right)
{
	Fraction result
	(
		left.get_numerator(),
		left.get_denominator() * right
	);
	result.reduction();
	return result;
}
Fraction operator / (int left, const Fraction& right)
{
	Fraction result
	(
		left * right.get_denominator(),
		right.get_numerator()
	);
	result.reduction();
	return result;
}
Fraction operator / (const Fraction& left, const Fraction& right)
{
	Fraction result
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()

	);
	result.reduction();
	return result;
}

bool operator== (const Fraction& left, const Fraction& right)
{
	if (left.decimal_form() == right.decimal_form()) return true;
	return false;
}
bool operator!= (const Fraction& left, const Fraction& right)
{
	if (left.decimal_form() != right.decimal_form()) return true;
	return false;
}
bool operator> (const Fraction& left, const Fraction& right)
{
	if (left.decimal_form() > right.decimal_form()) return true;
	return false;
}
bool operator>= (const Fraction& left, const Fraction& right)
{
	if (left.decimal_form() >= right.decimal_form()) return true;
	return false;
}
bool operator< (const Fraction& left, const Fraction& right)
{
	if (left.decimal_form() < right.decimal_form()) return true;
	return false;
}
bool operator<= (const Fraction& left, const Fraction& right)
{
	if (left.decimal_form() <= right.decimal_form()) return true;
	return false;
}

std::ostream& operator<< (std::ostream& os, const Fraction& obj)
{
	if (obj.get_numerator() == 0)
		os << 0;
	else if (obj.get_denominator() == 1)
		os << obj.get_numerator();
	else
		os << obj.get_numerator() << "/" << obj.get_denominator();
	return os;
}
std::istream& operator>> (std::istream& is, Fraction& obj)
{
	const int SIZE = 32;
	char buffer[SIZE]{};
	is.getline(buffer, SIZE);
	int number[2]{ 1, 1 };
	int n = 0;
	const char delimeters[] = "()\\+/";
	for (char* pch = strtok(buffer, delimeters);
		pch; pch = strtok(NULL, delimeters))
		number[n++] = atoi(pch);
	obj.set_numerator(number[0]);
	obj.set_denominator(number[1]);
	return is;
}