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
		if (x < 0)x = 0;
		if (x > 1000)x = 1000;
		this->x = x;
	}
	void set_y(double y)
	{
		if (y < 0)y = 0;
		if (y > 1000)y = 1000;
		this->y = y;
	}

	// Constructors
	//Point()
	//{
	//	x = y = 0;
	//	cout << "DefaultConstructor:\t" << this << endl;
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	// Increment/Decrement
	Point& operator++() // prefix increment
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int) // suffix increment
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}

	// Methods
	double distance_to(const Point& N) const
	{
		double length_x = this->x - N.get_x();
		double length_y = this->y - N.get_y();
		return sqrt(pow(length_x, 2) + pow(length_y, 2));
	}
	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
};

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

Point operator-(const Point& left, const Point& right)
{
	Point res(left.get_x() - right.get_x(), left.get_y() - right.get_y());
	return res;
}

bool operator==(const Point& left, const Point& right)
{
	if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;
}

double distance(const Point& a, const Point& b);

#define delimeter "\n------------------------------------\n"



//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS

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

#ifdef DISTANCE
	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << tab << A.get_y() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);
	//distance - расстояние до указанной точки

	cout << "\n------------------------------------\n";
	cout << distance(A, B) << endl;
	cout << "\n------------------------------------\n";
	cout << distance(B, A) << endl;
	cout << "\n------------------------------------\n";
	cout << B.distance_to(A) << endl;
	cout << "\n------------------------------------\n";
	cout << A.distance_to(B) << endl;
	cout << "\n------------------------------------\n";
#endif

#ifdef CONSTRUCTORS_CHECK
	Point A; // DefaultConstructor
	A.print();
	Point B(2, 3);
	B.print();
	Point C = B;
	C.print();

	Point D(A);
	D.print();

	Point E;
	E = C;
	Е.print();
	A = B;
	A.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	Point A, B, C;
	cout << delimeter << endl;
	A = B = C = Point(17, 18);
	cout << delimeter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK
	
#ifdef ARITHMETICAL_OPERATORS
	Point A(2, 3);
	Point B(3, 4);
	A += B;
	A.print();
	Point C = A + B;
	C.print();
	C = A - B;
	C.print();
	++C;
	C.print();
	Point D = C++;
	C.print();
	D.print();
#endif // ARITHMETICAL_OPERATORS

	Point A(2, 3);
	//Point B(3, 4);
	Point B = A;
	if (A == B++)
	{
		cout << "Точки равны" << endl;
	}
	else
	{
		cout << "Точки разные" << endl;
	}
}

double distance(const Point& a, const Point& b)
{
	double length_x = b.get_x() - a.get_x();
	double length_y = b.get_y() - a.get_y();
	return sqrt(pow(length_x, 2) + pow(length_y, 2));
}
