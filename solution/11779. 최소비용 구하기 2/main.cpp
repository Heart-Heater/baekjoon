// 1. 다익스트라 알고리즘으로 푸는 문제
// 2. 경로를 표시하기 위해서 mother array를 따로 만들어서 탐색하는 과정 중에 기록하고 나중에 출력하는 방식으로 풀었음
// ** 도시가 하나일때를 대비하여 출력을 케이스를 나누어서 해결 
//    알고리즘 내부에서 동시에 해결할 수 있을 것 같지만 시간이 없어서 그렇게 하지는 않음

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 100001
#define INF 1e9

using namespace std;

int n, m, a, b, c, x, y, dist[MAX], mother[MAX];
vector<pair<int, int>> graph[MAX];

void bfs(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    mother[start] = start;

    while (!pq.empty())
    {
        int D = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < D)
            continue;

        for (int i=0; i<graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int cost = D + graph[now][i].second;
            if (dist[next] > cost)
            {
                dist[next] = cost;
                mother[next] = now;
                pq.push({cost, next});
            }
        }


    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    cin >> x >> y;

    fill(dist, dist+MAX, INF);
    bfs(x);

    vector<int> trace;
    trace.push_back(y);
    int temp = mother[y];
    while (temp != x)
    {
        trace.push_back(temp);
        temp = mother[temp];
    }
    trace.push_back(x);

    cout << dist[y] << '\n';
    if (x == y)
        cout << 1 << '\n' << x;
    else
    {
        cout << trace.size() << '\n';
        for (int i=trace.size()-1; i>=0; i--)
            cout << trace[i] << ' ';
    }


}
