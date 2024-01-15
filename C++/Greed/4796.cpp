#include <iostream>
#include <vector>

void CampingDate(int L, int P, int V, int caseNum)
{
    int AbleDate;
    AbleDate = (V / P) * L + std::min(V % P, L);

    std::cout << "Case " << caseNum << ": " << AbleDate << std::endl;
}

int main()
{
    int L, P, V;
    int caseNum = 1;

    while (true)
    {
        std::cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0)
        {
            break;
        }

        CampingDate(L, P, V, caseNum);
        caseNum++;
    }

    return 0;
}
