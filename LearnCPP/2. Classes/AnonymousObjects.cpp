/*
    Anonymous Objects: A value that has no name.

Simple example:

    #include <iostream>

    int add(int x, int y)
    {
        int sum = x + y;
        return sum;
    }
    
    int main()
    {
        std::cout << add(5, 3);
    
        return 0;
    }

Now let's simplify below example using anonymous objects.
*/

#include <iostream>
 
class Cents
{
private:
    int m_cents;
 
public:
    Cents(int cents) { m_cents = cents; }
 
    int getCents() const { return m_cents; }
};
 
Cents add(const Cents &c1, const Cents &c2)
{
    Cents sum = Cents(c1.getCents() + c2.getCents());
    return sum;
}
 
int main()
{
    Cents cents1(6);
    Cents cents2(8);
    Cents sum = add(cents1, cents2);
    std::cout << "I have " << sum.getCents() << " cents." << std::endl;
 
    return 0;
}
