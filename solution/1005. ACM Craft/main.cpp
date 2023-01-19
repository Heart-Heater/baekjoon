// 1. 위상정렬 + DP 조합으로 풀 수 있는 또 다른 문제
//    비슷한 문제를 풀었기 때문에 비교적 쉽게 풀 수 있었음
// ** 함수의 포인터에 대해서 새롭게 공부할 수 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;

int tc, n, k, w;

void topologicalSort(int *Time, vector<int> *graph, int *indegree, int *ans)
{
    queue<int> q;
    for (int i=1; i<=n; i++)
    {
        if (!indegree[i])
        {
            q.push(i);
            ans[i] = Time[i];
        }
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (auto it : graph[now])
        {
            indegree[it]--;
            ans[it] = max(ans[it], ans[now]+Time[it]);
            if (!indegree[it])
                q.push(it);
        }

    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> tc;
    while (tc--)
    {

        cin >> n >> k;
        int Time[n+1], ans[n+1] = {0, }, indegree[n+1] = {0, };
        vector<int> graph[n+1];

        for (int i=1; i<=n; i++)
            cin >> Time[i];

        for (int i=0, x, y; i<k; i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }
        cin >> w;

        topologicalSort(Time, graph, indegree, ans);

        cout << ans[w] << '\n';

    }

}
