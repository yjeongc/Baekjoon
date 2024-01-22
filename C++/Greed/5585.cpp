#include <iostream>

int CountMomey(int Money)
{
    int count = 0;
    int ChangeList[] = {500, 100, 50, 10, 5 ,1};

    for (int i = 0; i<6; i++)
    {
        count += Money / ChangeList[i];
        Money %= ChangeList[i];
    }

    return count;
}


int main()
{

    int Money = 1, result = 0;
    std::cin >> Money;
    Money = 1000 - Money;

    result = CountMomey(Money);
    std::cout << result << std::endl;

    return 0;
}