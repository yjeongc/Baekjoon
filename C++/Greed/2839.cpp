#include <iostream>

int CountSuger(int Sugergram)
{
    int SugerUnit[] = {3, 5};

    for (int i = 0; i <= Sugergram / SugerUnit[0]; i++)
    {
        for (int j = 0; j <= Sugergram / SugerUnit[1]; j++)
        {
            if (Sugergram == (SugerUnit[0] * i + SugerUnit[1] * j))
            {
                return i + j;
            }
        }
    }

    return -1; // 정확하게 N킬로그램을 만들 수 없는 경우
}

int main()
{
    int Sugergram = 0, result = 0;
    std::cin >> Sugergram;

    result = CountSuger(Sugergram);
    std::cout << result << std::endl;

    return 0;
}
