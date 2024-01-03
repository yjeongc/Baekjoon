#include <iostream>
#include <iomanip>

int main()
{
    double val1, val2;
    std::cin >> val1 >> val2;

    std::cout << std::setprecision(9) << std::fixed << val1/val2 << std::endl;

    return 0;
}