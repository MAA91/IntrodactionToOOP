//IntrodactionToOOP
#include"stdafx.h"

class Point
{
	double x;
	double y;
public:
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
	double distance(Point A)const
	{
		return sqrt(pow(this->x - A.x, 2) + pow(this->y - A.y, 2));
	}
};


double distance(Point A, Point B)
{
	//return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
	return A.distance(B);
}

//#define STRUCT_POINT

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
	Point A, B;
	A.set_x(2);
	A.set_y(3);
	B.set_x(6);
	B.set_y(6);
	cout << A.distance(B) << endl;
	cout << distance(A, B) << endl;
}