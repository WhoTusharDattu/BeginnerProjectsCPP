#include <cstdint>
#include <iostream>

class RGBA{
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;

public:

    RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255)
        :m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {

    }

    void print()
    {
        std::cout << "r=" << static_cast<int>(m_red) <<
            " g=" << static_cast<int>(m_green) <<
            " b=" << static_cast<int>(m_blue) <<
            " a=" << static_cast<int>(m_alpha) << '\n';
    }
};


class A
{
public:
    A(int x)
    {
        std::cout << "A " << x << "\n";
    }
};
 
class B
{
private:
    A m_a;
public:
    B(int y) : m_a(y-1) // call A(int) constructor to initialize member m_a
    {
        std::cout << "B " << y << "\n";
    }
};

int main()
{
    RGBA teal(0, 127, 127);
    teal.print();

    /* Initializing member variables that are classes */
    B b(5);
    return 0;
}
