#include <iostream>

int CountMomey(int Money)
{
    int count = 0;

    //Money >= 500인 경우
    while(Money>=500)
    {
        Money -= 500;
        count++;
    }


    //Money >=100인 경우
    while (Money>=100)
    {
        Money -= 100;
        count++;
    }


    //Money >= 50인 경우
    while(Money>=50)
    {
        Money -= 50;
        count ++;
    }


    //Money >= 10인 경우
    while(Money>=10)
    {
        Money -= 10;
        count ++;
    }


    //Money >= 5인 경우
    while(Money>=5)
    {
        Money -= 5;
        count ++;
    }


    //Money >= 1인 경우
    while(Money>=1)
    {
        Money -= 1;
        count ++;
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