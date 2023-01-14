// 1. 0-1 BFS 알고리즘으로 풀 수 있는 문제
// ** 항상 n과 m 중에서 무엇이 가로, 세로인지 정확하게 파악하기

#include <iostream>
#include <string>
#include <deque>
#include <utility>
#define MAX 101

using namespace std;

int n, m;
string s, arr[MAX];
bool visited[MAX][MAX] = {false, };
int dist[MAX][MAX] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs_01()
{
    deque<pair<int, int>> dq;
    dq.push_front({1, 1});
    visited[1][1] = true;
    dist[1][1] = 0;

    while (!dq.empty())
    {
        int now_x = dq.front().first;
        int now_y = dq.front().second;
        dq.pop_front();

        if (now_x == n && now_y == m)
            break;

        for (int i=0; i<4; i++)
        {
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            if (arr[nx][ny-1] == '0')
            {
                if (1<=nx && nx<=n && 1<=ny && ny<=m && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    dq.push_front({nx, ny});
                    dist[nx][ny] = dist[now_x][now_y];
                }
            }

            if (arr[nx][ny-1] == '1')
            {
                if (1<=nx && nx<=n && 1<=ny && ny<=m && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    dq.push_back({nx, ny});
                    dist[nx][ny] = dist[now_x][now_y] + 1;
                }
            }

        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> s;
        arr[i] = s;
    }
    bfs_01();

    cout << dist[n][m];

}
