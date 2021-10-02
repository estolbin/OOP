#include<iostream>
#include<math.h>
using namespace std;
#define tab "\t"

class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
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
	double distance_to(Point N)
	{
		double length_x = this->x - N.get_x();
		double length_y = this->y - N.get_y();
		return sqrt(pow(length_x, 2) + pow(length_y, 2));
	}
};

double distance(Point a, Point b);

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POINT
	Point A;
	A.x = 2; A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT_POINT

	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << tab << A.get_y() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);
	//distance - расстояние до указанной точки

	cout << "Расстояние от точки А до точки B:" << distance(A, B) << endl;
	cout << "Расстояние от точки B до точки A:" << B.distance_to(A) << endl;
}

double distance(Point a, Point b)
{
	double length_x = b.get_x() - a.get_x();
	double length_y = b.get_y() - a.get_y();
	return sqrt(pow(length_x, 2) + pow(length_y, 2));
}
