#include <iostream>
#include <vector>
#include <queue> //우선순위큐 -> 힙과 같은 방식으로 작동함.

using namespace std;

const int number = 6; //노드의 수를 상수로 선언함.
int INF = 10000000;

vector<pair<int,int>>a[number]; //간선정보

int d[number]; //최소 비용

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int, int> > pq; //힙 구조

    //시작 노드를 우선순위 큐에 삽입
    pq.push(make_pair(start, 0));

    while(!pq.empty()){
        int current = pq.top().first; //현재 노드
        int distrance = -pq.top().second; //거꾸로 감.
        pq.pop();

        if(d[current] < distrance) //이미 처리한 노드라면 스킵
            continue;

        //현재 노드에 연결된 노드를 탐색함.
        for(int i = 0; i<a[current].size(); i++){
            int next = a[current][i].first; //다음 노드
            int nextDistrance = distrance + a[current][i].second; //다음 노드까지의 비용
            //다음 노드까지의 비용이 현재까지의 최소 비용보다 작다면 업데이트하고 우선순위 큐에 삽입.
            if(nextDistrance < d[next]){
                d[next] = nextDistrance;
                pq.push(make_pair(next, - nextDistrance)); //음수로 삽입 -> 최소값이 먼저 나옴.
            }
        } 
    }
}

int main(){
    for(int i = 1; i<number; i++){
        d[i] = INF;
    }

    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(3,5));
    a[1].push_back(make_pair(4,1));

    a[1].push_back(make_pair(1,2));
    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(2,2));

    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(2,2));

    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(2,2));

    dijkstra(1);

    for(int i = 1; i <=number; i++){
        cout << d[i] << "\n";
    }

    return 0;
}