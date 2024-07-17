#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, INT_MAX); //배열 초기화
    dp[0] = 0; // 0킬로그램을 만들기 위한 봉지의 개수는 0개

    // 다이나믹 프로그래밍 진행
    for (int i = 3; i <= N; i++) {
        if (dp[i - 3] != INT_MAX) // (i-3)킬로그램을 만들 수 있는 경우
            dp[i] = min(dp[i], dp[i - 3] + 1);
        if (dp[i - 5] != INT_MAX) // (i-5)킬로그램을 만들 수 있는 경우
            dp[i] = min(dp[i], dp[i - 5] + 1);
    }

    if (dp[N] == INT_MAX)
        cout << "-1" << endl;
    else
        cout << dp[N] << endl;

    return 0;
}
