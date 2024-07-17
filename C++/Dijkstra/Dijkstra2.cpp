#include <iostream>
#include <vector>
#include <queue> //�켱����ť -> ���� ���� ������� �۵���.

using namespace std;

const int number = 6; //����� ���� ����� ������.
int INF = 10000000;

vector<pair<int,int>>a[number]; //��������

int d[number]; //�ּ� ���

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int, int> > pq; //�� ����

    //���� ��带 �켱���� ť�� ����
    pq.push(make_pair(start, 0));

    while(!pq.empty()){
        int current = pq.top().first; //���� ���
        int distrance = -pq.top().second; //�Ųٷ� ��.
        pq.pop();

        if(d[current] < distrance) //�̹� ó���� ����� ��ŵ
            continue;

        //���� ��忡 ����� ��带 Ž����.
        for(int i = 0; i<a[current].size(); i++){
            int next = a[current][i].first; //���� ���
            int nextDistrance = distrance + a[current][i].second; //���� �������� ���
            //���� �������� ����� ��������� �ּ� ��뺸�� �۴ٸ� ������Ʈ�ϰ� �켱���� ť�� ����.
            if(nextDistrance < d[next]){
                d[next] = nextDistrance;
                pq.push(make_pair(next, - nextDistrance)); //������ ���� -> �ּҰ��� ���� ����.
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