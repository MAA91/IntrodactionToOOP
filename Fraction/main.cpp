//Fraction
#include"stdafx.h"

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction()
	{
		numerator = denominator = 1;
		cout << "DefaultConstractor:\t" << this << endl;
	}
	Fraction(int numerator)
	{
		this->numerator = numerator;
		this->denominator = 1;
		cout << "1ArgConstractor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constractor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstractor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destractor:\t" << this << endl;
	}

	int get_denominator()const
	{
		return denominator;
	}
	int get_numerator()const
	{
		return numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void print()const
	{
		if (numerator == 0)
			cout << 0 << endl;
		else if (denominator == 1)
			cout << numerator << endl;
		else
			cout << numerator << "/" << denominator << endl;
	}

	Fraction& operator= (const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator; 
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	Fraction& operator++()
	{
		numerator += denominator;
		return *this;
	}
	Fraction& operator--()
	{
		numerator -= denominator;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		numerator += denominator;
		return old;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		numerator -= denominator;
		return old;
	}
	void operator += (const Fraction& right)
	{
		numerator *= right.denominator;
		numerator += (right.numerator * denominator);
		denominator *= right.denominator;
		this->reduction();
	}
	void operator -= (const Fraction& right)
	{
		numerator *= right.denominator;
		numerator -= (right.numerator * denominator);
		denominator *= right.denominator;
		this->reduction();
	}
	void operator *= (const Fraction& right)
	{
		numerator *= right.numerator;
		denominator *= right.denominator;
		this->reduction();
	}
	void operator /= (const Fraction& right)
	{
		numerator *= right.denominator;
		denominator *= right.numerator;
		this->reduction();
	}

	void reduction()
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
	double decimal_form()const
	{
		return (double)numerator / denominator;
	}
	int integer_part()const
	{
		return numerator / denominator;
	}
	double fractional_part()const
	{
		return this->decimal_form() - this->integer_part();
	}
};

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
bool operator> (const Fraction & left, const Fraction & right)
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

//#define GET_SET_CHECK
//#define CONSTRUCTORS_CHECK
//#define PARTS_CHECK
#define ARIFMETICALO_OPERATORS_CHECK


void main()
{
#ifdef GET_SET_CHECK
	Fraction A;
	A.set_numerator(4);
	A.set_denominator(3);
	A.print();
	cout << A.get_numerator() << "\t" << A.get_denominator() << endl;
#endif // GET_SET_CHECK

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(2, 3);
	C.print();

	Fraction D = C;
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef PARTS_CHECK
	Fraction A(-120, -105);
	A.print();
	A.reduction();
	cout << "Reduction: "; A.print();
	cout << "Decimal form: " << A.decimal_form() << endl;
	cout << "Integer part: " << A.integer_part() << endl;
	cout << "Fractional part: " << A.fractional_part() << endl;
#endif // PARTS_CHECK

#ifdef ARIFMETICALO_OPERATORS_CHECK
	Fraction A(5, 3); 
	Fraction B(2, 5);
	A *= B;
	A.print();
#endif // OPERATORS_CHECK

}