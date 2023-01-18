// 1. 위상정렬 알고리즘 + 우선순위 큐 
// 2. 위상정렬을 하는 과정에서 숫자가 작은 것부터 나오게 하는 방법에 대해서 많은 시간 고민을 했음
//    결국에는 문제 분류의 도움을 받아 '우선순위 큐'에 대한 힌트를 얻었고 그 이후로 쉽게 풀렸음
// ** 막상 풀어보니 정말 간단한 문제였지만 자료구조 자체를 바꾼다는 생각을 하지 못했음
//    평소에도 기본 알고리즘에서 자료구조를 바꿨을 때 어떠한 변화가 생기는지도 생각하면서 공부해야할듯

#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

int n, m, indegree[MAX], x, y;
vector<int> graph[MAX];

void topologicalSort()
{
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=1; i<=n; i++)
    {
        if (indegree[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int now = pq.top();
        pq.pop();
        result.push_back(now);

        for (auto it : graph[now])
        {
            indegree[it]--;
            if (!indegree[it])
                pq.push(it);
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
