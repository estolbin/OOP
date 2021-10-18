#include <iostream>
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


    // methods
    void print() const
    {
        cout << numerator << " / " << denominator << endl;
    }


};

bool denominators_equal(const Fraction& left, const Fraction& right)
{
    if (left.get_denominator() == right.get_denominator())
        return true;
    else
        return false;
}

// вычитать и складывать можно только с одинаковым знаменателем
Fraction operator+(const Fraction& left, const Fraction& right)
{
    if (denominators_equal(left, right))
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

    Fraction aa(4, 7);
    Fraction bb(2, 5);
    Fraction res2 = aa / bb;
    res2.print();

    Fraction A(1);
    A.print();
#endif 
}