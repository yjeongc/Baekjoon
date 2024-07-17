#include <iostream>
#include <queue>

using namespace std;

//ť�� ����� ��ȣ �ִ� �Լ�
void input(int N, queue<int> &q){
    for (int i = 1; i <= N; ++i)
            q.push(i);
}


//k��° ����� ť���� ���� & �� ������ �̵���Ű�� �Լ�
void MoveP(int K, queue<int>&q){
    cout << "<";
    while (q.size() > 1) { //ť�� ũ�Ⱑ 1���� ū ���� �ݺ���.
        for (int i = 0; i < K-1; i++) {
            int front = q.front(); //�� �տ� �ִ� ��� ��ȯ
            q.pop();
            q.push(front);
        }
        // K��° ����� ť���� ����
        cout << q.front();
        q.pop();

        // ť�� �����ִ� ����� �ִٸ� �޸� ���
        if (!q.empty())
            cout << ", ";
    }

    cout << q.front() << ">";
}


// �似Ǫ�� �Լ�
void josephus(int N, int K, queue<int> &q) {
    
    input(N, q);

    MoveP(K, q);
}


int main() {
    int N, K;
    cin >> N;
    cin >> K;

    queue<int> q;

    josephus(N, K, q);

    return 0;
}
