#include <iostream>
#define SQUARE(x) ((x)*(x))

int main()
{
    std::cout << SQUARE(5) << std::endl;
    std::cout << SQUARE (2.7) << std::endl;

    return 0;
}