#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector<int>& Wine, int N){
    for(int i = 0; i < N; i++){
        cin >> Wine[i];
    }
}

void DP(vector<int>& dp, vector<int>& Wine, int N){
    dp[0] = Wine[0];
    dp[1] = Wine[0] + Wine[1];
    dp[2] = max({dp[1], Wine[0] + Wine[2], Wine[1] + Wine[2]});

    for(int j = 3; j < N; j++){
        dp[j] = max(dp[j-1], max(dp[j-2] + Wine[j], dp[j-3] + Wine[j-1] + Wine[j]));
    }

    cout << dp[N-1];
}

int main(){
    int N;
    cin >> N;
    vector<int> Wine(N);

    input(Wine, N);

    vector<int> dp(N);
    DP(dp, Wine, N);

    return 0;
}
