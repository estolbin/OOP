#include<iostream>
using namespace std;
#define tab "\t"

class Point
{
	double x;
	double y;
public:
};

#define STRUCT_POINT

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



}