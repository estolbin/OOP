#include <iostream>
#include<string>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    void set_numerator(int num)
    {
        this->numerator = num;
    }
    void set_denominator(int num)
    {
        if (num <= 0) num = 1;
        this->denominator = num;
    }
    int get_numerator() const
    {
        return numerator;
    }
    int get_denominator() const
    {
        return denominator;
    }
    // constructors, destructor
    Fraction(int num = 1, int denom = 1)
    {
        this->numerator = num;
        this->denominator = denom;
    }
    ~Fraction()
    {
    }
    // operators
    Fraction& operator=(const Fraction& other)
    {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        return *this;
    }
    Fraction& operator++()
    {
        // нет условий инкремента.
        this->numerator++;
        this->denominator++;
        return *this;
    }
    Fraction operator++(int)
    {
        Fraction old = *this;
        this->numerator++;
        this->denominator++;
        return old;
    }
    Fraction& operator--()
    {
        // нет условий декремента.
        this->numerator--;
        this->denominator--;
        return *this;
    }
    Fraction operator--(int)
    {
        Fraction old = *this;
        this->numerator--;
        this->denominator--;
        return old;
    }
    bool operator==(const Fraction& left) // лучше за классом, но для примера - в классе
    {
        return (this->numerator == left.numerator && this->denominator == left.denominator);
    }
    // methods
    void print() const
    {
        //cout << numerator << " / " << denominator << endl;
        cout << view() << endl;
    }
    bool denominator_equal(const Fraction& other) const
    {
        return this->denominator == other.denominator;
    }
    string view() const
    {
        string v = to_string(numerator) + " / " + to_string(denominator);
        return v;
    }
};

bool denominators_equal(const Fraction& left, const Fraction& right)
{
    if (left.get_denominator() == right.get_denominator())
        return true;
    else
        return false;
}

bool operator>(const Fraction& left, const Fraction& right)
{
    int a = left.get_numerator() * right.get_denominator();
    int b = right.get_numerator() * left.get_denominator();

    return a > b;
}

bool operator<(const Fraction& left, const Fraction& right)
{
    int a = left.get_numerator() * right.get_denominator();
    int b = right.get_numerator() * left.get_denominator();

    return a < b;
}


// вычитать и складывать можно только с одинаковым знаменателем
Fraction operator+(const Fraction& left, const Fraction& right)
{
    //if (denominators_equal(left, right))
    if (left.denominator_equal(right))
    {
        Fraction res(left.get_numerator() + right.get_numerator(), left.get_denominator());
        return res;
    }
    else
    {
        Fraction res(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(), left.get_denominator() * right.get_denominator());
        return res;
    }
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
    if (denominators_equal(left, right))
    {
        Fraction res(left.get_numerator() - right.get_numerator(), left.get_denominator());
        return res;
    }
    else
    {
        Fraction res(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(), left.get_denominator() * right.get_denominator());
        return res;
    }
    //return res;
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
    Fraction res(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());
    return res;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
    Fraction res(left.get_numerator() * right.get_denominator(), left.get_denominator() * right.get_numerator());
    return res;
}

#define TEST_FRACTIONS

void main()
{
    Fraction frac(3, 5);
    frac.print();

#ifdef TEST_FRACTIONS
    Fraction one(13, 29);
    Fraction two(7, 29);
    Fraction res = one + two;
    res.print();

    Fraction ab(3, 5);
    Fraction bc(4, 7);
    Fraction res_ab = ab + bc;
    res_ab.print();

    Fraction first(5, 8);
    Fraction second(3, 4);
    Fraction res1 = first * second;
    res1.print();

    string first_view = first.view();
    string second_view = second.view();

    string e = (first > second) ? "Yes" : "No";
    cout << first_view << "  >  " << second_view << "\t" << e << endl;


    Fraction aa(4, 7);
    Fraction bb(2, 5);
    Fraction res2 = aa / bb;
    res2.print();

    Fraction A(1);
    A.print();

    A++;
    A.print();
#endif 
}