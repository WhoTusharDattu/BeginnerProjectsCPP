#include "Class.h"

int main()
{

    DateClass today {2017, 06, 14};

    today.m_day = 30;
    today.print();

    return 0;
}