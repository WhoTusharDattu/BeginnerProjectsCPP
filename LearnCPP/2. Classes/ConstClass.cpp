/*
const class objects can only explicitly call const member functions
A const member function is a member function that guarantees it will not modify the object
    or call any non-const member functions (as they may modify the object).

*/

#include <iostream>

#if 1 //Simple example
class Something
{
public:
    int m_value;
 
    Something() { m_value= 0; }
 
    void resetValue() { m_value = 0; }
    void setValue(int value) { m_value = value; }
 
    int getValue() const; // note addition of const keyword here
};
 
int Something::getValue() const // and here
{
    return m_value;
}

int main()
{
    const Something something; // calls default constructor
 
    something.m_value = 5; // compiler error: violates const
    something.setValue(5); // compiler error: violates const
 
    std::cout << something.getValue() << std::endl;

    return 0;
}

#else //Const reference


class Date
{
private:
    int m_year;
    int m_month;
    int m_day;
 
public:
    Date(int year, int month, int day)
    {
        setDate(year, month, day);
    }
 
    void setDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
 
    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};
 
// note: We're passing date by const reference here to avoid making a copy of date
void printDate(const Date &date)
{
    std::cout << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << '\n';
}
 
int main()
{
    Date date(2017, 6, 16);
    printDate(date);
 
    return 0;
}
#endif
