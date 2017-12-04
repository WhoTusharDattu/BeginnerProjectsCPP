#include <cassert>
#include <iostream>

//#define NORMAL

#ifdef NORMAL
class Calc
{
private:
    int m_value;

public:
    Calc() { m_value = 0; }

    void add(int value) { m_value += value; }
    void sub(int value) { m_value -= value; }
    void mult(int value) { m_value *= value; }

    int getValue() { return m_value; }
};

#else
class Calc
{
private:
    int m_value;

public:
    Calc() { m_value = 0; }

    Calc& add(int value) { m_value += value; return *this;}
    Calc& sub(int value) { m_value -= value; return *this;}
    Calc& mult(int value) { m_value *= value; return *this;}

    int getValue() { return m_value; }
};
#endif


int main()
{
    Calc calc;

#ifdef NORMAL
    calc.add(5); // returns void
    calc.sub(3); // returns void
    calc.mult(4); // returns void
#else
    calc.add(5).sub(3).mult(5);
#endif
    std::cout << calc.getValue() << '\n';
    return 0;
}