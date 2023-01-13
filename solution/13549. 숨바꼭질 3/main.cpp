// 1. 0-1 BFS 알고리즘을 새롭게 배울 수 있는 문제
//    모든 간선의 가중치가 0과 1로만 이루어져있을 때 O(V+E)의 선형 시간안에 해결할 수 있는 좋은 알고리즘
// 2. deque을 이용하여 가중치가 0이면 front에 1이면 back에 넣어준다
//    여기서 중요한 점은 해당 깊이에서 연결된 노드들을 탐색할 때 가중치가 0인 것부터 해야함.
//    그 이유는 도착지점이 k가 되었을 때 break 하기 때문인데 1인 가중치를 먼저 넣게 되면 0인 가중치를 탐방하기 전에 break 되어 오류가 뜸
//    이 문제는 graph를 따로 만들지 않아도 되었지만 만약 graph 객체(인접 리스트 등)을 직접 만들어야 한다면 가중치가 0인 노드부터 나오게 하던게
//    처음부터 그렇게 넣어야함
// 3. 비슷한 이유로 단순 BFS로는 풀기 어려운 문제. 아예 우선순위 큐를 사용하여 다익스트라를 쓰던가 해야함

#include <iostream>
#include <deque>
#include <utility>
#define MAX 100001

using namespace std;

int n, k;
bool visited[MAX] = {false, };

int bfs(int start)
{
    int ans = 0;
    deque<pair<int, int>> dq;
    dq.push_front({start, 0});
    visited[start] = true;

    while (!dq.empty())
    {
        int temp = dq.front().first;
        int dist = dq.front().second;
        dq.pop_front();

        if (temp == k)
        {
            ans = dist;
            break;
        }

        if (2*temp<MAX && !visited[2*temp])
        {
            visited[2*temp] = true;
            dq.push_front({2*temp, dist});
        }

        if (temp+1<MAX && !visited[temp+1])
        {
            visited[temp+1] = true;
            dq.push_back({temp+1, dist+1});
        }

        if (temp-1>=0 && !visited[temp-1])
        {
            visited[temp-1] = true;
            dq.push_back({temp-1, dist+1});
        }


    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    int ans = bfs(n);

    cout << ans;
}
