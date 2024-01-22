#include <iostream>
#include <queue>
#include <functional>

int main() {
    int N;
    std::cin >> N;

		//우선 순위 큐 선언. 최소힙을 사용한다.
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;


		//우선 순위 큐에 값을 넣는다.
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        pq.push(num);
    }

    int result = 0;

		//우선순위 큐의 크기가 1보다 큰 동안 반복한다.
		//즉, 합치지 않은 순자 묶음이 2개 이상일 때까지 반복한다.
    while (pq.size() > 1) {
        int a = pq.top(); //우선순위 큐에서 가장 작은 것을 꺼냄.
        pq.pop(); //가장 작은 것 삭제.
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        result += sum;
        pq.push(sum); //합친 크기를 우선순위 큐에 넣는다. 가장 작은 크기의 두 묶음을 합칠 수 있도록 하기 위해.
    }

    std::cout << result;

    return 0;
}