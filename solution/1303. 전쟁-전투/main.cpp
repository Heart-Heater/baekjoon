// 1. BFS를 이용하여 품
// 2. 오랜만에 2차원에서 탐색하는 BFS를 복습할 수 있었음
// 3. 가로가 n, 세로가 m 이었음. 처음에 반대로 해서 틀렸음
// ** 항상 문제를 잘 읽자. 특히, 가로와 세로는 혼동하지 

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;

int n, m, my_ans, enemy_ans;
string arr[MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> checking()
{
    pair<int, int> result = make_pair(0, 0);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if (!visited[i][j])
            {
                result = make_pair(i, j);
                return result;
            }
        }
    return result;
}

void bfs()
{
    pair<int, int> curr = checking();
    int i = curr.first;
    int j = curr.second;

    while (curr.first != 0 && curr.second != 0)
    {
        queue<pair<int, int>> q;
        visited[i][j] = true;
        q.push({i, j});

        int cnt = 0;
        char side = arr[i][j-1];
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            cnt++;
            for (int k=0; k<4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (1<=nx && nx<=n && 1<=ny && ny<=m)
                {
                    if (!visited[nx][ny] && arr[nx][ny-1]==side)
                    {
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }


            }
        }
        if (side == 'W')
            my_ans += cnt*cnt;
        else
            enemy_ans += cnt*cnt;

        curr = checking();
        i = curr.first;
        j = curr.second;

    }



}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int i=1; i<=n; i++)
        cin >> arr[i];

    bfs();

    cout << my_ans << ' ' << enemy_ans;

}
