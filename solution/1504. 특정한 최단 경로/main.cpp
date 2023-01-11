// 1. 다익스트라 알고리즘을 구간별로 계산하는 문제였음
//    조건 1 : 특정한 두 지점을 반드시 통과하여야 하고,
//    조건 2 : 모든 노드와 간선은 횟수 상관없이 무제한 이동 가능하기 때문에
//    다익스트라 알고리즘을 구간별로 나누어 계산해도 무방할 것이라고 생각하였음
// 2. 1 --> v1 --> v2 --> N  과  1 --> v2 --> v1 --> N  이렇게 두 가지가 존재할 수 있기 때문에 둘다 계산하여 최소값을 취함
// 3. -1을 출력하는 경우에 대해서 경우별로 나누어 구현시킴
//
// ** 다익스트라 알고리즘을 목적지에 도착하는 순간 끊어버리는 방법에 익숙해지고 

#include <iostream>
#include <queue>
#include <vector>
#define MAX 801
#define INF 1e9

using namespace std;

int n, e, v1, v2, a, b, c;
vector<pair<int, int>> graph[MAX];

int dijkstra(int start, int desti)
{
    int dist[MAX];
    fill(dist, dist+MAX, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d > dist[now])
        {
            if (now == desti)
                break;
            else
                continue;
        }

        for (int i=0; i<graph[now].size(); i++)
        {
            int cost = d + graph[now][i].second;
            if (cost < dist[graph[now][i].first])
            {
                dist[graph[now][i].first] = cost;
                pq.push({cost, graph[now][i].first});
            }
        }

    }

    return dist[desti];

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> e;
    for (int i=0; i<e; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    int mid = dijkstra(v1, v2);

    if (mid == INF)
    {
        cout << -1;
        return 0;
    }
    else
    {
        int case_1_1 = dijkstra(1, v1);
        int case_1_2 = dijkstra(v2, n);
        if (case_1_1 == INF || case_1_2 == INF)
        {
            cout << -1;
            return 0;
        }
        else
        {
            int case_2_1 = dijkstra(1, v2);
            int case_2_2 = dijkstra(v1, n);
            cout << min(case_1_1 + mid + case_1_2, case_2_1 + mid + case_2_2);
            return 0;
        }
    }


}
