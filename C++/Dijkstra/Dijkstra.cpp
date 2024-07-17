#include <iostream>
#include <vector>

using namespace std;

const int INF = 999; // ������ �ǹ��ϴ� ��

// ���ͽ�Ʈ�� �˰��� �Լ�
void dijkstra(int N, int start, vector<vector<int>>& edges) {
    vector<int> dist(N, INF); // ���������κ����� �ִ� �Ÿ��� �����ϴ� ����
    vector<bool> visited(N, false); // �湮 ���θ� �����ϴ� �迭

    dist[start] = 0; // �������� �ִ� �Ÿ��� 0

    // ��� ��带 �湮�� ������ �ݺ��Ѵ�.
    for (int i = 0; i < N; i++) {
        int u = -1; // ���� ���õ� ��尡 ����.
        int minDist = INF; //�ִܰŸ��� ��Ÿ���� ���� minDist

        // ���� �湮���� ���� ��� �߿��� �ִ� �Ÿ��� ���� ��带 �����Ѵ�.
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] < minDist) {
                u = j;
                minDist = dist[j];
            }
        }

        // ������ ��带 �湮 ó��
        visited[u] = true;

        // ������ ��带 ���� �ٸ� ���� ���� ��θ� ������Ʈ��
        for (int k = 0; k < N; k++) {
            //���õ� ���u�� ���k���̿� ������ �����ϴ��� Ȯ�� && ���ݱ����� �ִܰ�� dist[k]���� dist[u]+edges[u][k]�� ���� ���� ������.
            if (edges[u][k] != 0 && dist[k] > dist[u] + edges[u][k]) {
                dist[k] = dist[u] + edges[u][k];
            }
        }
    }

    // ��� ���
    for (int i = 0; i < N; i++) {
        if (dist[i] == INF) cout << "0 "; //�ִ� �Ÿ��� INF�� �����ִٸ� "0"�� �����
        else cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    // ���� ������ �����ϴ� 2���� ����
    vector<vector<int>> edges(N, vector<int>(N, 0));

    // ���� ���� �Է� �ޱ�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> edges[i][j];
        }
    }

    // ���ͽ�Ʈ�� �˰��� ���� & ��� ���
    for (int i = 0; i < N; i++) {
        dijkstra(N, i, edges);
    }

    return 0;
}
