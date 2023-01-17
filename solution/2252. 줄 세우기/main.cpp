// 1. 위상정렬 문제
//    queue를 이용한 위상정렬 문제로 쉽게 풀 수 있었음

#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001

using namespace std;

int n, m, indegree[MAX], x, y;
vector<int> graph[MAX];

void topologicalSort()
{
    vector<int> result;
    queue<int> q;
    for (int i=1; i<=n; i++)
    {
        if (!indegree[i])
        {
            q.push(i);
            result.push_back(i);
        }
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (auto it : graph[now])
        {
            indegree[it]--;
            if (!indegree[it])
            {
                q.push(it);
                result.push_back(it);
            }
        }
    }
    for (auto it : result)
        cout << it << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        indegree[y]++;
    }

    topologicalSort();

}
