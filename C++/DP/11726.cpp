#include <iostream>
#include <vector>

using namespace std;


int Solution(vector<int>&DP, int n){
    DP[1] = 1;
    DP[2] = 2;
    
    for(int i = 3; i<n+1; i++){
        DP[i] = DP[i-1] + DP[i-2];
    }

    return DP[n];
}


int main(){

    int n;
    cin >> n;

    vector<int>DP(n+1); //인덱스를 1부터 사용하기 위해서.

    int result = Solution(DP, n);

    cout << result % 10007;

    return 0;
}