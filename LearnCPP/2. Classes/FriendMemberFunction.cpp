/*
    Code has intentional errors!!!
    Let's solve them! ;)

Reasons:
    In order to make a member function a friend, the compiler has to have seen
        the full definition for the class of the friend member function (not just a forward declaration).

    > So let's move Display class above!
    > Turns out, displayItem need to see Storage class definition as well!
*/

#include <iostream>

class Display; // forward declaration for class Display

class Storage
{
private:
    int m_nValue;
    double m_dValue;
public:
    Storage(int nValue, double dValue)
    {
        m_nValue = nValue;
        m_dValue = dValue;
    }

    // Make the Display class a friend of Storage
    friend void Display::displayItem(Storage& storage); // error: Storage hasn't seen the full definition of class Display
};

class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItem(Storage& storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << " " << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << " " << storage.m_nValue << '\n';
    }
};

int main()
{
    Storage storage(5, 6.7);

    Display display(false);
    display.displayItem(storage);

    return 0;
}
