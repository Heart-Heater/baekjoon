// 1. BFS와 tuple을 이용하여 풀 수 있는 문제
//    tuple에 대해서 새롭게 알 수 있었음. BFS 문제이지만 visited 배열을 만들 필요가 없었음
// 2. 초기화 : make_tuple
// 3. 접근 : get<0>(tp),  get<1>(tp),  get<2>(tp)

#include <iostream>
#include <queue>
#include <tuple>
#define MAX 101

using namespace std;

int m, n, h, cnt, temp, ans;
int dn[6] = {1, 0, -1, 0, 0, 0};
int dm[6] = {0, -1, 0, 1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};
int box[MAX][MAX][MAX];
queue<tuple<int, int, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n >> h;

    for (int i=1; i<=h; i++)
    {
        for (int j=1; j<=n; j++)
        {
            for (int k=1, x; k<=m; k++)
            {
                cin >> x;
                box[i][j][k] = x;
                if (x == 1)
                {
                    cnt++;
                    q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    while (!q.empty())
    {
        int z = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        q.pop();

        cnt--;


        for (int i=0, nz, nx, ny; i<6; i++)
        {
            nz = z + dh[i];
            nx = x + dn[i];
            ny = y + dm[i];
            if (1<=nz && nz<=h && 1<=nx && nx<=n && 1<=ny && ny<=m)
            {
                if (box[nz][nx][ny] == 0)
                {
                    box[nz][nx][ny] = 1;
                    q.push(make_tuple(nz, nx, ny));
                }
            }
        }

        if (cnt == 0)
        {
            ans++;
            cnt = q.size();
        }

    }

    for (int i=1; i<=h; i++)
    {
        for (int j=1; j<=n; j++)
        {
            for (int k=1, x; k<=m; k++)
            {
                if (box[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << ans-1;

}
