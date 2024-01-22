#include <iostream>

int CountMomey(int N, int Money, int* CoinList)
{
    int count = 0;
    
    for (int i = N-1; i>=0; i--)
    {
        count += Money / CoinList[i];
        Money %= CoinList[i];
    }


    return count;
}


int main()
{

    int N = 0, Money = 0, result = 0;
    std::cin >> N >> Money;

    int* CoinList = new int [N];

    for (int i = 0; i< N; i++)
    {
        std::cin >> CoinList[i];
    }


    result = CountMomey(N, Money, CoinList);
    std::cout << result << std::endl;


    delete[] CoinList; //메모리 누수를 방지하기 위해 동적할당한 배열을 해제한다.

    return 0;
}