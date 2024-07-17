#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> Sushi(N);
    for(int i = 0; i < N; i++) {
        cin >> Sushi[i];
    }

    map<int, int> countMap;
    int count = 0, maxVariety = 0;

    // 초기값 미리 넣기
    for (int i = 0; i < k; i++) {
        if (countMap[Sushi[i]] == 0) count++;
        countMap[Sushi[i]]++;
    }

    if (countMap[c] == 0) count++;
    countMap[c]++;

    maxVariety = count;

 
    for (int start = 1; start < N; start++) {
        int end = (start + k - 1) % N;

        // 시작 초밥을 제거함
        countMap[Sushi[start - 1]]--;
        if (countMap[Sushi[start - 1]] == 0) count--;

        // 새로운 초밥을 추가함
        if (countMap[Sushi[end]] == 0) count++;
        countMap[Sushi[end]]++;

        // 쿠폰 초밥을 다시 계산함
        if (countMap[c] == 0) count++;
        countMap[c]++;

        maxVariety = max(maxVariety, count);
    }

    cout << maxVariety;

    return 0;
}