// 1. 다익스트라 알고리즘을 이용하여 해결
// 2. 다익스트라 알고리즘을 사용할 수 있는 기본적인 형태와는 조금 다름
// 3. 한 지점에서 여러 지점까지의 최단 거리가 아닌 여러 지점에서 한 지점으로의 최단 거리를 계산해야함
// 4. 반복문으로 모든 지점에 대해서 다익스트라 알고리즘을 적용하되 원하는 도달 지점이 되면 break를 해서 속도를 높임
// 5. 마지막으로 나가는 경우에 있어서는 기본적인 다익스트라 알고리즘을 적용

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 1e9

using namespace std;

int n, m, x, a, b, c;
vector<pair<int, int>> graph[MAX];
int dist_out[MAX];

int dijkstra_in(int start, int desti)
{

    int dist[MAX];
    fill(dist, dist+MAX, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int D = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < D)
        {
            if (now == x)
                break;
            else
                continue;
        }

        for (int i=0; i<graph[now].size(); i++)
        {
            int cost = D + graph[now][i].second;
            if (cost < dist[graph[now][i].first])
            {
                dist[graph[now][i].first] = cost;
                pq.push({cost, graph[now][i].first});
            }
        }
    }

    return dist[x];

}


void dijkstra_out(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist_out[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int D = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist_out[now] < D)
            continue;
        for (int i=0; i<graph[now].size(); i++)
        {
            int cost = D + graph[now][i].second;
            if (cost < dist_out[graph[now][i].first])
            {
                dist_out[graph[now][i].first] = cost;
                pq.push({cost, graph[now][i].first});
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> x;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    fill(dist_out, dist_out+MAX, INF);

    dijkstra_out(x);

    for (int i=1; i<=n; i++)
    {
        if (i != x)
            dist_out[i] += dijkstra_in(i, x);
    }

    cout << *max_element(dist_out+1, dist_out+1+n);
}
