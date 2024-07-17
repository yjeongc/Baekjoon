#include <iostream>
#include <vector>
using namespace std;

int Solution(vector<int>&DP, int N){
    DP[1] = 1;    
    DP[2] = 2;   
    DP[3] = 4;     
    for(int i = 4; i<=N; i++){
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3] ;
    }
    return DP[N];
}

int main(){
    int n;    
    cin >> n;
    vector<int>DP(n+1); //인덱스를 1부터 사용하기 위해서.
    int result = Solution(DP, n);
    cout << result << "\n";
    return 0;
}