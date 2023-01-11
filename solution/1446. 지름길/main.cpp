// 1. 다익스트라 알고리즘에 대해서 배울 수 있는 문제
// 2. 플로이드 워셜과는 다르게 특정 지점에서 모든 지점까지 가는 최소거리를 구하는 알고리즘
// 3. 처음에는 각 지름길의 시작점과 끝점을 어떻게 노드로 구현할까에 대해서 고민했었음
// 4. 그렇게 할 필요 없이 모든 점을 노드라고 생각하고 길이가 1인 간선을 이어주면 되었음
// ** 다익스트라는 우선순위 큐 구조를 이용하여 O(NlogN) 속도로 만들 수 있음
// *** 다익스트라 알고리즘 구현 자체가 쉽지 않았음. 
// **** https://github.com/ndb796/python-for-coding-test/blob/master/9/2.cpp 참조
// ***** 우선순위 큐에서 내림차순으로 빼내는 방법 기억하기
// ***** 공부하다가 tuple 구조도 알게 되었는데 나중에 다시 

#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
#define MAX 10013

using namespace std;

int n, d, a, b, c;
vector<pair<int, int>> graph[MAX];
int dist[MAX];


void dijkstra(int start) {

      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

      pq.push({0, start});
      dist[start] = 0;

      while (!pq.empty()) {

            int D = pq.top().first;
            int now = pq.top().second;
            pq.pop();

            if (dist[now] < D) continue;
            for (int i=0; i<graph[now].size(); i++) {
                  int cost = D + graph[now][i].second;

                  if (cost < dist[graph[now][i].first]) {
                        dist[graph[now][i].first] = cost;
                        pq.push(make_pair(cost, graph[now][i].first));
                  }
            }
      }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;

    for (int i=0; i<d; i++)
        graph[i].push_back({i+1, 1});

    for (int i=0; i<n; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    fill(dist, dist+MAX, INF);

    dijkstra(0);

    cout << dist[d];


}
