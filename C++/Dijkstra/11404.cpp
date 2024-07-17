#include <iostream>
#include <vector>

using namespace std;

const int INF = 999; // 무한을 의미하는 값

// 다익스트라 알고리즘 함수
void dijkstra(int N, int start, vector<vector<int>>& edges) {
    vector<int> dist(N, INF); // 시작점으로부터의 최단 거리를 저장하는 벡터
    vector<bool> visited(N, false); // 방문 여부를 저장하는 배열

    dist[start] = 0; // 시작점의 최단 거리는 0

    // 모든 노드를 방문할 때까지 반복한다.
    for (int i = 0; i < N; i++) {
        int u = -1; // 아직 선택된 노드가 없음.
        int minDist = INF; //최단거리를 나타내는 변수 minDist

        // 아직 방문하지 않은 노드 중에서 최단 거리를 갖는 노드를 선택한다.
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] < minDist) {
                u = j;
                minDist = dist[j];
            }
        }

        // 선택한 노드를 방문 처리
        visited[u] = true;

        // 선택한 노드를 거쳐 다른 노드로 가는 경로를 업데이트함
        for (int k = 0; k < N; k++) {
            //선택된 노드u와 노드k사이에 간선이 존재하는지 확인 && 지금까지의 최단경로 dist[k]보다 dist[u]+edges[u][k]가 작을 때만 수행함.
            if (edges[u][k] != 0 && dist[k] > dist[u] + edges[u][k]) {
                dist[k] = dist[u] + edges[u][k];
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        if (dist[i] == INF) cout << "0 "; //최단 거리가 INF로 남아있다면 "0"을 출력함
        else cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int N, M;
    cin >> N >> M;

    // 간선 정보를 저장하는 2차원 벡터
    vector<vector<int>> edges(N, vector<int>(N, INF));

    // 간선 정보 입력 받기
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a - 1][b - 1] = min(edges[a - 1][b - 1], c); // 두 도시를 연결하는 버스가 여러 개일 수 있으므로 최소 비용으로 업데이트
    }

    // 다익스트라 알고리즘 적용 & 결과 출력
    for (int i = 0; i < N; i++) {
        dijkstra(N, i, edges);
    }

    return 0;
}
