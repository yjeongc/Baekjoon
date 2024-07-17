#include <iostream>
#include <vector>

using namespace std;


long long fib(vector<long long>&numbers, int num)
{
    if (numbers[num] == -1){
        numbers[num] = fib(numbers, num - 1) + fib(numbers, num - 2);
    }

    return numbers[num];
}



int main()
{
    int N;
    cin >> N;

    vector<long long> numbers(N+1,-1);
    numbers[0] = 0;
    numbers[1] = 1;

    cout << fib(numbers, N) << endl;

    return 0;
}