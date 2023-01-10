// 1. BFS로 접근하는 간단한 문제
// 2. 최대값을 찾고 해당 index를 출력하는 형태로 제출

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int n, m;
vector<int> v[MAX];

int bfs(int& curr)
{
    int ans = 0;
    bool check[n+1] = {false, };
    queue<int> q;
    q.push(curr);
    check[curr] = true;
    while (!q.empty())
    {
        ans++;
        int temp = q.front();
        q.pop();
        for (int i=0; i<v[temp].size(); i++)
        {
            int cand = v[temp][i];
            if (!check[cand])
            {
                check[cand] = true;
                q.push(cand);
            }
        }
    }

    return ans;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int a, b;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b;
        v[b].push_back(a);
    }

    int result[n+1];
    for (int i=1; i<=n; i++)
    {
        result[i] = bfs(i);
    }

    int max_ = *max_element(result+1, result+n+1);

    for (int i=1; i<=n; i++)
    {
        if (result[i] == max_)
            cout << i << ' ';
    }


}
