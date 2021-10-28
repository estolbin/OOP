#include<iostream>
using namespace std;

class Fraction;

Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer; // целая часть
	int numerator; // числитель
	int denominator; // знаменатель
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	//			Constructors
	Fraction()
	{
		integer = numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		set_denominator(1);
		cout << "1argConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)  
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//			Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		/*Fraction temp = *this + other;
		integer = temp.integer;
		numerator = temp.numerator;
		denominator = temp.denominator;
		return *this;*/
		return *this = *this + other;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
    Fraction& operator/=(const Fraction& other)
    {
        return *this = *this / other;
    }
    Fraction& operator-=(const Fraction& other)
    {
        return *this = *this - other;
    }
	//		Increment/Decrement
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
    Fraction &operator--()
    {
        integer--;
        return *this;
    }
    Fraction operator--(int)
    {
        Fraction old = *this;
        integer--;
        return old;
    }

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	//			Methods
	
	// Выделяет из неправильной дроби целую часть
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	// Целую часть интегрирует в числитель
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	// Обращает дробь
	Fraction& inverse()
	{
		to_improper();
		int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;
	}

	void print() const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		if (integer == 0 && numerator == 0) cout << 0;
		cout << endl;
	}
    friend ostream& operator<<(ostream& os, const Fraction& obj);
	friend istream& operator>>(istream& os, const Fraction& obj);
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	//Fraction result(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	//result.to_proper();
	//return result;
	return Fraction
	(
		left.get_numerator() * right.get_numerator(), 
		left.get_denominator() * right.get_denominator()
	).to_proper();

}

Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();*/
	return left * right.inverse();
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();

	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
    left.to_proper();
    right.to_proper();

    return Fraction
    (
         left.get_integer() - right.get_integer(),
         left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
         left.get_denominator() * right.get_denominator()
    ).to_proper();
}

bool operator>(Fraction left, Fraction right)
{
    left.to_proper();
    right.to_proper();

    return (left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator());
}
bool operator<(Fraction left, Fraction right)
{
    left.to_proper();
    right.to_proper(); 

    return (left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator());
}
bool operator!=(Fraction left, Fraction right)
{
    return (left > right || left < right);
}
bool operator==(Fraction left, Fraction right)
{
    if (left != right) return false;
    return true;
}
bool operator>=(Fraction left, Fraction right)
{
    if (left > right || left == right) return true;
    return false;
}
bool operator<=(Fraction left, Fraction right)
{
    if (left < right || left == right) return true;
    return false;
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.integer) cout << obj.integer;
	if (obj.numerator)
	{
		if (obj.integer) cout << "(";
		cout << obj.numerator << "/" << obj.denominator;
		if (obj.integer) cout << ")";
	}
	if (obj.integer == 0 && obj.numerator == 0) cout << 0;
	//cout << endl;
	return os;
}

istream& operator>>(istream& is, Fraction& obj)
{
    cout << "Введите дробь - целое, числитель, знаменатель:";
	int integer, numerator, denominator;
    is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
    return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A; // Default constructor
	A.print();
	Fraction B = 5; // Single-arg constructor
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction E = D; // Copy constructor
	E.print();
	Fraction F;
	F = D;
	F.print();

#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(23, 3);
	A.print();
	//A.to_proper();
	//A.print();
	//A.to_improper();
	//A.print();
	Fraction B(8, 4, 5);
	B.print();

	Fraction C = A * B;
	C.print();

	(A / B).print();
	(A + B).print();
	A *= B;
	//A.print();
	cout << A << endl;
#endif // ARITHMETICAL_OPERATORS_CHECK
	//for (Fraction A(1, 2); A.get_integer() < 10; A++)
	//{
	//	cout << A << "\t";
	//}

	Fraction A(1, 2);
	A(7, 4, 5);
	cout << A << endl;

	Fraction B;
	cin >> B;
	cout << B << endl;

	B--;
	cout << B << endl;

	if (A != B) cout << "Dont equal" << endl;

	Fraction C = A;
	if (A == C) cout << "Equal" << endl;


}
