//IntrodactionToOOP
#include"stdafx.h"

class Point
{
private:
	double x;
	double y;
public:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstractor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstractor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constractor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstractor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destractor:\t" << this << endl;
	}
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	} 
	double distance(const Point& other)const
	{
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
	void print()const
	{
		cout << "( " << x << ", " << y << " )\n";
	}
};


double distance(const Point& A, const Point& B)
{
	//return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
	return A.distance(B);
}

//#define STRUCT_POINT
#define DISTANSE_CHECK
//#define CONSTRUCTORS_CHECK


void main()
{
	setlocale(0, "");
#ifdef STRUCT_POINT
	Point A; // Объявление переменной 'A' типа 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT
#ifdef DISTANSE_CHECK
	Point A, B;
	A.set_x(2);
	A.set_y(3);
	B.set_x(6);
	B.set_y(6);
	cout << A.distance(B) << endl;
	cout << distance(A, B) << endl;
#endif // DISTANSE_CHECK
#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTORS_CHECK


}