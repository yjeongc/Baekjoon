#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, INT_MAX); //�迭 �ʱ�ȭ
    dp[0] = 0; // 0ų�α׷��� ����� ���� ������ ������ 0��

    // ���̳��� ���α׷��� ����
    for (int i = 3; i <= N; i++) {
        if (dp[i - 3] != INT_MAX) // (i-3)ų�α׷��� ���� �� �ִ� ���
            dp[i] = min(dp[i], dp[i - 3] + 1);
        if (dp[i - 5] != INT_MAX) // (i-5)ų�α׷��� ���� �� �ִ� ���
            dp[i] = min(dp[i], dp[i - 5] + 1);
    }

    if (dp[N] == INT_MAX)
        cout << "-1" << endl;
    else
        cout << dp[N] << endl;

    return 0;
}
