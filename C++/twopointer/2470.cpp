#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 2000000000

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int>ValueNumber(N);
    vector<int>ReturnIndex(2);

    for(int i=0; i<N; i++){
        cin >> ValueNumber[i];
    }

    sort(ValueNumber.begin(), ValueNumber.end());
    
    int left = 0, right = N-1, sum = 0,absSum = 0, minSum = INF;

    while(left != right){
        sum = ValueNumber[left] + ValueNumber[right];
        absSum = abs(sum);
        if (absSum < minSum){
            minSum = absSum;
            ReturnIndex[0] = ValueNumber[left];
            ReturnIndex[1] = ValueNumber[right];
        }
        if(sum < 0){
            left++;
        }
        else right--;
    }

    cout << ReturnIndex[0] << " " << ReturnIndex[1];

    return 0;
}