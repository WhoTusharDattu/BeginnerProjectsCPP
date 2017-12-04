#include <iostream>

class Accumulator
{
    int m_value;

public:
    Accumulator()
    {
        m_value = 0;
    }
    void add(int value)
    {
        m_value += value;
    }
    int get_value()
    {
        return m_value;
    }

    friend void reset(Accumulator& accumulator);
};

void reset(Accumulator& accumulator)
{
    accumulator.m_value = 0;
}

int main()
{
    Accumulator acc;

    acc.add(5);
    std::cout << "Current value: " << acc.get_value() << std::endl;
    reset(acc);
    std::cout << "Value after reset: " << acc.get_value() << std::endl;

    return 0;
}
