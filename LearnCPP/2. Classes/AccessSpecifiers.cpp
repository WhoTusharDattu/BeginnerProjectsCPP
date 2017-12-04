/*

C++ provides 3 different access specifier keywords: public, private, and protected.
Public and private are used to make the members that follow them public members or private members respectively.

The third access specifier, protected, works much like private does.
Useful in inheritance.


When a function has access to the private members of a class,
it can access the private members of any object of that class type that it can see.

Benefits of encapsulation:
    1. Encapsulated classes are easier to use and reduce the complexity of your programs
    2. Encapsulated classes help protect your data and prevent misuse
    3. Encapsulated classes are easier to change
*/

#include <iostream>

class DateClass
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    void set_date(int year, int month, int day)
    {
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void print()
    {
        std::cout << m_year << "/" << m_month << "/"<< m_day << std::endl;
    }

    void copy_from(const DateClass &d)
    {
        m_month = d.m_month;
        m_day = d.m_day;
        m_year = d.m_year;
    }
};

int main()
{

    DateClass date;
    date.set_date(2017, 06, 14);

    //Error, because m_day is private member
    /* date.m_day = 30; */

    std::cout << "Print date: " << std::endl;
    date.print();

    DateClass copy;

    date.set_date(2017, 06, 15);
    copy.copy_from(date);

    std::cout << "Print copy: " << std::endl;
    copy.print();

    return 0;
}