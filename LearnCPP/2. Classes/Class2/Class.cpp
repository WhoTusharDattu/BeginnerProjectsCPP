#include <iostream>
#include "Class.h"

void DateClass::print()
{
    std::cout << m_year << "/" << m_month << "/"<< m_day << std::endl;
}
