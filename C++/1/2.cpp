#include <iostream>

int main()
{
    int val1;
    std::cout << "input your first number: ";
    std::cin >> val1;

    int val2;
    std::cout << "input your secound number: ";
    std::cin >> val2;

    int result = val1 + val2;
    std::cout << "result : " << result << std::endl;


    return 0;
}