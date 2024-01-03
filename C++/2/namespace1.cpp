#include <iostream>

namespace Company1
{
    void func(void)
    {
        std::cout << "Company1이 정의한 함수" << std::endl;
    }
}

namespace Company2
{
    void func(void)
    {
        std::cout << "Company2이 정의한 함수" << std::endl;
    }
}

int main()
{
    Company1::func();
    Company2::func();

    return 0;
}