#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1; //벡터의 크기에서 1을 뺀만큼.

    while (low <= high) {

        int mid = low + (high - low) / 2; //처음과 마지막 차이를 2로 나눈 다음 앞 부분만큼 더해서 mid를 나타냄.
                                          //c++에서는 소수점을 버리고 정수로 값을 저장함.
        // 중앙값이 찾고자 하는 수와 같은지 확인함
        if (arr[mid] == target) {
            return mid; // 찾은 경우 인덱스 반환    
        } else if (arr[mid] > target) {
            high = mid - 1; // 중앙값이 찾고자 하는 수보다 큰 경우 뒷 부분 삭제
        } else {
            low = mid + 1; // 중앙값이 찾고자 하는 수보다 작은 경우 앞 부분 삭제
        }
    }

    return -1; // 원하는 요소를 찾지 못한 경우 -1 반환
}


int main() {
    int N = 0;
    cin >> N;

    vector<int> numbers(N); //N은 벡터의 초기 크기를 의미함. 초기 크기를 지정하면 모든 요소가 0으로 초기화됨.
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    // 입력된 숫자들 정렬
    sort(numbers.begin(), numbers.end());

    int M;
    cin >> M;


    for (int i = 0; i < M; ++i) {
        int target;
        cin >> target; //찾고자 하는 수

        // 이진 탐색 수행
        int result = binarySearch(numbers, target);

        // 결과 출력
        cout << result << " ";
    }

    return 0;
}
