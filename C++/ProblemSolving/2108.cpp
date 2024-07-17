#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


// 산술평균 함수
int Mean(int N, const vector<int>& numbers) {
    double sum = 0;

    for (unsigned  i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    return round(sum/N);
}


// 중앙값 함수
int Median(const vector<int>& numbers) {

    vector<int> sortedNumbers = numbers;
    
    sort(sortedNumbers.begin(), sortedNumbers.end());
    
    int size = numbers.size();
    if (size % 2 == 0) { // 짝수일 때
        return (sortedNumbers[size / 2 - 1] + sortedNumbers[size / 2]) / 2;
    } else { // 홀수일 때
        return sortedNumbers[size / 2];
    }

}


// 최빈값 함수
int Mode(const vector<int>& v, int N) {
    int count[8001] = {0}; // 입력 벡터의 값을 카운트할 배열 초기화

    // 입력 벡터의 값들을 순회하면서 각 값의 빈도수를 카운트
    for (int i = 0; i < N; i++) {
        if (v[i] >= 0) {
            count[v[i]]++; // 양수일 경우, 해당 인덱스의 카운트를 증가
        } else {
            count[abs(v[i]) + 4000]++; // 음수일 경우, 인덱스를 4000을 더한 후 카운트를 증가
        }
    }

    int maxCount = count[0]; // 최대 빈도수를 저장할 변수 초기화
    for (int i = 0; i < 8001; i++) {
        if (maxCount < count[i]) { // 최대 빈도수 갱신
            maxCount = count[i];
        }
    }

    vector<int> modes; // 최빈값을 저장할 벡터 초기화
    for (int i = 0; i < 8001; i++) {
        if (count[i] == maxCount) { // 최대 빈도수와 같은 값들을 모두 modes 벡터에 추가
            if (i <= 4000) { // 음수인 경우 인덱스를 되돌려서 modes 벡터에 추가
                modes.push_back(i);
            } else {
                modes.push_back((i - 4000) * (-1));
            }
        }
    }

    sort(modes.begin(), modes.end()); // modes 벡터를 정렬

    // modes 벡터의 크기에 따라 반환할 값을 결정
    if (modes.size() == 1) { // modes 벡터의 크기가 1이면 해당 값을 반환
        return modes[0];
    } else { // modes 벡터의 크기가 1보다 크면 두 번째로 작은 값을 반환
        return modes[1];
    }
}


// 범위 함수
int Range(const vector<int>& numbers) {
    // 최댓값과 최솟값 초기화
    int maxVal = numbers[0];
    int minVal = numbers[0];

    // 최댓값과 최솟값 찾기
    for (unsigned  i = 1; i < numbers.size(); i++) {
        if (numbers[i] > maxVal) {
            maxVal = numbers[i];
        }
        if (numbers[i] < minVal) {
            minVal = numbers[i];
        }
    }

    return maxVal - minVal;
}


int main() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    // 결과 출력
    cout << Mean(N, numbers) << endl;
    cout << Median(numbers) << endl;
    cout << Mode(numbers, N) << endl;
    cout << Range(numbers) << endl;

    return 0;
}
