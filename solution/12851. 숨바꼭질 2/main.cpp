// 1. 다익스트라로 접근하는 문제
// 2. 하지만, 모든 경로를 세야 했기 때문에 도착 지점에서 바로 break 할 수가 없었음
// 3. visited를 q에 push하는 경우에 true로 체크하는 것이 아닌 pop할 때 true로 체크했음
//    이와 같은 방법이 통하는 이유는 같은 깊이에서 도착 지점이 같은 경우는 걸리는 시간이 모두 같지만,
//    한 단계라도 더 깊게 들어가는 순간 최단 거리가 아니게 됨. 그 이후로 도착 지점 k로 가봤자 최단 시간이 아님
//    따라서, k가 발견된 깊이에서 끊어주되 해당 깊이에서 모든 k를 세주면 됨

#include <iostream>
#include <queue>
#include <utility>
#define MAX 100001

using namespace std;

int n, k, cnt, visited[MAX] = {false, };

int bfs(int start)
{
    int ans;
    int check = MAX;
    queue<pair<int, int>> q;
    q.push({start, 0});

    while (!q.empty())
    {
        int temp = q.front().first;
        int dist = q.front().second;
        q.pop();

        visited[temp] = true;

        if (temp == k && check == MAX)
        {
            cnt++;
            check = dist;
            ans = dist;
        }
        else if (temp == k && check == dist)
            cnt++;
        else if (check < dist)
            break;

        if (temp+1<MAX && !visited[temp+1])
            q.push({temp+1, dist+1});

        if (temp-1>=0 && !visited[temp-1])
            q.push({temp-1, dist+1});

        if (2*temp<MAX && !visited[2*temp])
            q.push({2*temp, dist+1});

    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    int ans = bfs(n);

    cout << ans << '\n' << cnt;
}

