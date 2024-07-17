#include <iostream>
#include <queue>

using namespace std;

//큐에 사람들 번호 넣는 함수
void input(int N, queue<int> &q){
    for (int i = 1; i <= N; ++i)
            q.push(i);
}


//k번째 사람을 큐에서 제거 & 맨 앞으로 이동시키는 함수
void MoveP(int K, queue<int>&q){
    cout << "<";
    while (q.size() > 1) { //큐의 크기가 1보다 큰 동안 반복함.
        for (int i = 0; i < K-1; i++) {
            int front = q.front(); //맨 앞에 있는 사람 반환
            q.pop();
            q.push(front);
        }
        // K번째 사람을 큐에서 제거
        cout << q.front();
        q.pop();

        // 큐에 남아있는 사람이 있다면 콤마 출력
        if (!q.empty())
            cout << ", ";
    }

    cout << q.front() << ">";
}


// 요세푸스 함수
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
