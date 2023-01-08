// 1. DFS를 이용하는 문제
// 2. r과 c가 5 이하로 시간이 오래 걸리지 않을 것이라고 생각
// 3. 현재까지의 거리가 k 보다 클 경우 더이상 고려하지 않고 return --> 백트래킹
// ** DFS 오랜만에 복습할 수 있는 기회였음
// *** 백트래킹에 대해서 좀 더 공부할 필요 있음

#include <iostream>
#include <string>

using namespace std;

int r, c, k, ans;
string map[6];
bool dp[6][6];

void solution(int x, int y, int dist)
{
    if (dist > k)
        return;

    if (dist==k && x==1 && y==c)
    {
        ans++;
        return;
    }

    if (x-1 >=1 && !dp[x-1][y] && map[x-1][y-1]!='T')
    {
        dp[x-1][y] = true;
        solution(x-1, y, dist+1);
        dp[x-1][y] = false;
    }
    if (y+1 <= c && !dp[x][y+1] && map[x][y]!='T')
    {
        dp[x][y+1] = true;
        solution(x, y+1, dist+1);
        dp[x][y+1] = false;
    }
    if (x+1 <= r && !dp[x+1][y] && map[x+1][y-1]!='T')
    {
        dp[x+1][y] = true;
        solution(x+1, y, dist+1);
        dp[x+1][y] = false;
    }
    if (y-1 >= 1 && !dp[x][y-1] && map[x][y-2]!='T')
    {
        dp[x][y-1] = true;
        solution(x, y-1, dist+1);
        dp[x][y-1] = false;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> r >> c >> k;
    for (int i=1; i<=r; i++)
        cin >> map[i];

    dp[r][1] = true;
    solution(r, 1, 1);

    cout << ans;

}
