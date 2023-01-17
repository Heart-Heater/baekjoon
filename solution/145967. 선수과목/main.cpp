// 1. 위상정렬을 처음 공부하게 되었음
//    기본적으로 queue를 이용하여 풀었지만, 재귀를 이용한 DFS 방법도 있다고 함. 새로 공부해야할 필요성 있음
// 2. 위상정렬 알고리즘 자체가 어렵지는 않지만 응용문제를 더 풀어볼 필요성이 있음

#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

int n, m, a, b, indegree[MAX], semester[MAX];
vector<int> graph[MAX];

void topologySort()
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
        semester[i] = 1;
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++)
        {
            indegree[graph[now][i]] -= 1;
            if (indegree[graph[now][i]] == 0)
            {
                q.push(graph[now][i]);
                semester[graph[now][i]] = semester[now] + 1;
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
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    topologySort();

    for (int i=1; i<=n; i++)
        cout << semester[i] << ' ';
}
