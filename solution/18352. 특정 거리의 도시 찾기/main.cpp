// 1. BFS로 쉽게 풀 수 있는 문제

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 300001

using namespace std;

int n, m, k, x, a, b;
vector<int> graph[MAX];
bool visited[MAX];
vector<int> ans;

void bfs(int start)
{
    queue<pair<int, int>> q;
    q.push({0, start});
    visited[start] = true;

    while (!q.empty())
    {
        int now = q.front().second;
        int dist = q.front().first;
        q.pop();

        if (dist == k)
            ans.push_back(now);

        if (dist > k)
            break;

        for (int i=0; i<graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (!visited[next])
            {
                visited[next] = true;
                q.push({dist+1, next});
            }
        }

    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> x;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    bfs(x);

    if (!ans.size())
        cout << -1;
    else
    {
        sort(ans.begin(), ans.end());
        for (auto it : ans)
            cout << it << '\n';
    }

}
