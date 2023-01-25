// 1. 지문 자체가 모호한 요소가 있어서 그것을 이해하는데 어려움이 있었지만 구현 자체는 굉장히 간단한 예제

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, r, c, d, room[50][50], ans;
int left_r[4] = {0, -1, 0, 1};
int left_c[4] = {-1, 0, 1, 0};
int back_r[4] = {1, 0, -1, 0};
int back_c[4] = {0, -1, 0, 1};

int direction(int d)
{
    if (d == 0) return 3;
    else if (d == 1) return 0;
    else if (d == 2) return 1;
    else return 2;
}

void solution()
{
    queue<pair<int, int>> q;
    q.push({r, c});
    room[r][c] = 3;
    ans++;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int check = 0;
        while (check != 4)
        {
            int nr = x + left_r[d];
            int nc = y + left_c[d];
            if (room[nr][nc] == 0)
            {
                d = direction(d);
                room[nr][nc] = 3;
                ans++;
                q.push({nr, nc});
                break;

            }
            else if (room[nr][nc] == 1 || room[nr][nc] == 3)
            {
                d = direction(d);
                check++;
            }
        }

        if (check == 4)
        {
            int nr_ = x + back_r[d];
            int nc_ = y + back_c[d];
            if (room[nr_][nc_] == 0)
            {
                room[nr_][nc_] = 1;
                ans++;
                q.push({nr_, nc_});
            }
            else if (room[nr_][nc_] == 3)
            {
                q.push({nr_, nc_});
            }
            else return;
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> r >> c >> d;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cin >> room[i][j];
        }

    solution();
    cout << ans;
}
