// 1. 플로이드 워셜 알고리즘을 배운 김에 한번 더 풀어봄
// 2. 문제에 시작 노드와 도착 노드가 같아도 거리가 다른 경우가 주어질 수도 있다고 나와있음
// 3. graph 배열에 추가할 때 최소값으로 추가하면 해결 가능
// 4. 비교적 쉬운 알고리즘에 속함

#include <iostream>
#define INF 1e9

using namespace std;

int n, m, graph[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i=1; i<101; i++)
        fill(graph[i], graph[i]+101, INF);

    for (int i=1; i<101; i++)
        graph[i][i] = 0;

    cin >> n >> m;
    for (int i=0; i<m ;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(c, graph[a][b]);
    }

    for (int k=1; k<=n; k++)
    {
        for (int a=1; a<=n; a++)
        {
            for (int b=1; b<=n; b++)
            {
                graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b]);
            }
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (graph[i][j]==INF)
                cout << 0 << ' ';
            else
                cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }



}
