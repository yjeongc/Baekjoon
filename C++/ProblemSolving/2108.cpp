#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


// ������ �Լ�
int Mean(int N, const vector<int>& numbers) {
    double sum = 0;

    for (unsigned  i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    return round(sum/N);
}


// �߾Ӱ� �Լ�
int Median(const vector<int>& numbers) {

    vector<int> sortedNumbers = numbers;
    
    sort(sortedNumbers.begin(), sortedNumbers.end());
    
    int size = numbers.size();
    if (size % 2 == 0) { // ¦���� ��
        return (sortedNumbers[size / 2 - 1] + sortedNumbers[size / 2]) / 2;
    } else { // Ȧ���� ��
        return sortedNumbers[size / 2];
    }

}


// �ֺ� �Լ�
int Mode(const vector<int>& v, int N) {
    int count[8001] = {0}; // �Է� ������ ���� ī��Ʈ�� �迭 �ʱ�ȭ

    // �Է� ������ ������ ��ȸ�ϸ鼭 �� ���� �󵵼��� ī��Ʈ
    for (int i = 0; i < N; i++) {
        if (v[i] >= 0) {
            count[v[i]]++; // ����� ���, �ش� �ε����� ī��Ʈ�� ����
        } else {
            count[abs(v[i]) + 4000]++; // ������ ���, �ε����� 4000�� ���� �� ī��Ʈ�� ����
        }
    }

    int maxCount = count[0]; // �ִ� �󵵼��� ������ ���� �ʱ�ȭ
    for (int i = 0; i < 8001; i++) {
        if (maxCount < count[i]) { // �ִ� �󵵼� ����
            maxCount = count[i];
        }
    }

    vector<int> modes; // �ֺ��� ������ ���� �ʱ�ȭ
    for (int i = 0; i < 8001; i++) {
        if (count[i] == maxCount) { // �ִ� �󵵼��� ���� ������ ��� modes ���Ϳ� �߰�
            if (i <= 4000) { // ������ ��� �ε����� �ǵ����� modes ���Ϳ� �߰�
                modes.push_back(i);
            } else {
                modes.push_back((i - 4000) * (-1));
            }
        }
    }

    sort(modes.begin(), modes.end()); // modes ���͸� ����

    // modes ������ ũ�⿡ ���� ��ȯ�� ���� ����
    if (modes.size() == 1) { // modes ������ ũ�Ⱑ 1�̸� �ش� ���� ��ȯ
        return modes[0];
    } else { // modes ������ ũ�Ⱑ 1���� ũ�� �� ��°�� ���� ���� ��ȯ
        return modes[1];
    }
}


// ���� �Լ�
int Range(const vector<int>& numbers) {
    // �ִ񰪰� �ּڰ� �ʱ�ȭ
    int maxVal = numbers[0];
    int minVal = numbers[0];

    // �ִ񰪰� �ּڰ� ã��
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

    // ��� ���
    cout << Mean(N, numbers) << endl;
    cout << Median(numbers) << endl;
    cout << Mode(numbers, N) << endl;
    cout << Range(numbers) << endl;

    return 0;
}
