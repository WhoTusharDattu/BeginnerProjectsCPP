/*

*/

#include <cassert>
#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction( )
    {
/*         m_numerator = 0;
        m_denominator = 1; */
    }

    Fraction(int numerator, int denominator = 1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator()
    {
        return m_numerator;
    }
    int getDenominator()
    {
        return m_denominator;
    }
    double getValue()
    {
        return static_cast<double>(m_numerator) / m_denominator;
    }
};

/*
    By default, when the outer class is constructed, the member variables will have their default constructors called.
    This happens before the body of the constructor executes.
*/

class A
{
public:
    A() { std::cout << "A\n"; }
};
 
class B
{
private:
    A m_a; // B contains A as a member variable
 
public:
    B() { std::cout << "B\n"; }
};

int main()
{

    int x(5);
    std::cout << "\nInt value: " << x << std::endl;

    Fraction one;

    Fraction five_third(5, 3);
    Fraction six(6);

    //Fraction six = Fraction(6); // Copy initialize a Fraction, will call Fraction(6, 1)

    std::cout << "Five third: ";
    std::cout << five_third.getNumerator() << "/" << five_third.getDenominator() << '\n';

    std::cout << "Six: ";
    std::cout << six.getNumerator() << "/" << six.getDenominator() << '\n';

    std::cout << "\nInstance of B created below : \n";
    B b;

    return 0;
}