/*
    Static member functions have no *this pointer
    Static member functions can only access static member variables.
*/

#include <iostream>

class Something
{
private:
    static int s_idGenerator;
    int m_id;
 
public:
    Something() { m_id = s_idGenerator++; } // grab the next value from the id generator
 
    int getID() const { return m_id; }

    static int getValue() { return s_idGenerator; } // static member function
};
 
// Note that we're defining and initializing s_idGenerator even though it is declared as private above.
// This is okay since the definition isn't subject to access controls.
int Something::s_idGenerator = 1; // start our ID generator with value 1
 
int main()
{
    Something first;
    Something second;
    Something third;
 
    std::cout << first.getID() << '\n';
    std::cout << second.getID() << '\n';
    std::cout << third.getID() << '\n';

    std::cout << "\nCalled static member function below:" << std::endl;
    std::cout << Something::getValue() << '\n';

    return 0;
}
