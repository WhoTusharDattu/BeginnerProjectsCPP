/*
    1) The destructor must have the same name as the class, preceded by a tilde (~).
    2) The destructor can not take arguments.
    3) The destructor has no return type.
*/

#include <cassert>
#include <iostream>

class IntArray
{
    int *m_array;
    int m_length;

public:
    IntArray(int length)
    {
        assert(length > 0);
        m_array = new int[length];
        m_length = length;
    }

    ~IntArray()
    {
        delete[] m_array;
    }

    void setValue(int index, int value) { m_array[index] = value; }
    int& getValue(int index) { return m_array[index]; }
 
    int getLength() { return m_length; }
};

int main()
{
    IntArray ar(10);
    for (int count = 0; count < 10; ++count)
        ar.setValue(count, count + 1);
    std::cout << "The value of element 5 is: " << ar.getValue(5) << std::endl;

    return 0;
}