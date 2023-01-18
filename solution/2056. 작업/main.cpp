// 1. 위상정렬 + 점화식을 이용한 Bottom-up DP
// 2. 처음에는 위상정렬을 진행하지 않고, Top-down DP를 사용하였음. 테스트 케이스 모두 통과하였지만 9%에서 실패
//    아직도 이 방법이 왜 틀렸는지 모르겠음
//    자신으로 들어오는 노드들까지의 걸린 시간 중 최대값에 현재 걸리는 시간을 더하는 DP인데 반례를 못 찾겠음
//    위상정렬을 하지 않는만큼 정렬 과정 중에서 오류가 있는 것 같음
// 3. 맞은 풀이는 위상 정렬을 하는 과정 중 똑같은 점화식을 사용하여 해결하였음

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001

using namespace std;

int n, Time[MAX], x, y, ans[MAX], indegree[MAX];
vector<int> graph[MAX];

void topologicalSort()
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

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> Time[i] >> x;
        indegree[i] = x;
        for (int j=0; j<x; j++)
        {
            cin >> y;
            graph[y].push_back(i);
        }
    }

    topologicalSort();

    cout << *max_element(ans+1, ans+n+1);


}
