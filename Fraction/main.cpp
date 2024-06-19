//Fraction
#include"stdafx.h"
#include"Fraction.h"

//#define GET_SET_CHECK
//#define CONSTRUCTORS_CHECK
//#define PARTS_CHECK
//#define ARIFMETICALO_OPERATORS_CHECK
#define CONVERTIONS_FROM_OTHER_TO_CLASS
//#define CONVERTIONS_FROM_CLASS_TO_OTHER
//#define CONVERSIONS_TASK_1
//#define CONVERSIONS_TASK_2

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
	//A *= B;
	cin >> A;
	cout << A << endl;
#endif // OPERATORS_CHECK

#ifdef CONVERTIONS_FROM_OTHER_TO_CLASS
	Fraction B;
	B = Fraction(5);
#endif // CONVERTIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERTIONS_FROM_CLASS_TO_OTHER
	Fraction A(102, 4);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;

	double b = (double)A;
	cout << b << endl;
#endif // CONVERTIONS_FROM_CLASS_TO_OTHER

#ifdef CONVERSIONS_TASK_1
	Fraction A(3, 4);
	cout << A << endl;

	//int a = (int)A;
	double a = A;
	cout << a << endl;

#endif // CONVERSIONS_TASK_1

#ifdef CONVERSIONS_TASK_2
	Fraction B = .333;
	cout << B << endl;
#endif // CONVERSIONS_TASK_2
}