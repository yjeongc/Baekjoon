#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1; //������ ũ�⿡�� 1�� ����ŭ.

    while (low <= high) {

        int mid = low + (high - low) / 2; //ó���� ������ ���̸� 2�� ���� ���� �� �κи�ŭ ���ؼ� mid�� ��Ÿ��.
                                          //c++������ �Ҽ����� ������ ������ ���� ������.
        // �߾Ӱ��� ã���� �ϴ� ���� ������ Ȯ����
        if (arr[mid] == target) {
            return mid; // ã�� ��� �ε��� ��ȯ    
        } else if (arr[mid] > target) {
            high = mid - 1; // �߾Ӱ��� ã���� �ϴ� ������ ū ��� �� �κ� ����
        } else {
            low = mid + 1; // �߾Ӱ��� ã���� �ϴ� ������ ���� ��� �� �κ� ����
        }
    }

    return -1; // ���ϴ� ��Ҹ� ã�� ���� ��� -1 ��ȯ
}


int main() {
    int N = 0;
    cin >> N;

    vector<int> numbers(N); //N�� ������ �ʱ� ũ�⸦ �ǹ���. �ʱ� ũ�⸦ �����ϸ� ��� ��Ұ� 0���� �ʱ�ȭ��.
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    // �Էµ� ���ڵ� ����
    sort(numbers.begin(), numbers.end());

    int M;
    cin >> M;


    for (int i = 0; i < M; ++i) {
        int target;
        cin >> target; //ã���� �ϴ� ��

        // ���� Ž�� ����
        int result = binarySearch(numbers, target);

        // ��� ���
        cout << result << " ";
    }

    return 0;
}
