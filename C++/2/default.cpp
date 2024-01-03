#include <iostream>

int Adder(int num1=1, int num2=2)
{
    return num1 + num2;
}

int main()
{
    std::cout << Adder() << std::endl; //Adder(1,2)
    std::cout << Adder(5) << std::endl; //Adder(5,2)
    std::cout << Adder(3,5) << std::endl; //Adder(3,5)

    return 0;
}