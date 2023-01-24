// 1. BFS를 이용하여 연결되어 있는 그래프를 찾는 문제
// 2. 크게 어려운 부분이 없었는데 배열 선언에 있어서 variable을 그대로 사용하여 모든 경우에서 작동하였지만 한 가지 경우에서 계속 잘못된 결과를 출력했음
//    코드블락에서는 variable로 선언해도 오류 없이 컴파일링 되서 문제를 찾는데 오래 걸림
//    레플릿에서 똑같은 코드를 돌려보았을 때 해당 오류가 발생했고 배열을 선언시 variable을 사용하면 안되는 것을 깨달았음
// ** 다른 문제에서 variable로 배열 선언한적 있는거같은데...어쨋든 이렇게 선언하면 안되는 것을 

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int n, ans_normal, ans_abnormal;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
string s[100];

void solution(int n)
{
    bool normal[100][100] = {false, };
    bool abnormal[100][100] = {false, };


    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            if (normal[i][j]) continue;
            else
            {
                queue<pair<int, int>> q;
                normal[i][j] = true;
                q.push({i, j});
                char temp = s[i][j];

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k=0; k<4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (!normal[nx][ny] && 0<=nx && nx<n && 0<=ny && ny<n && s[nx][ny]==temp)
                        {
                            normal[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                ans_normal++;
            }

            if (abnormal[i][j]) continue;
            else
            {
                queue<pair<int, int>> q;
                abnormal[i][j] = true;
                q.push({i, j});
                char temp = s[i][j];

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k=0; k<4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (!abnormal[nx][ny] && 0<=nx && nx<n && 0<=ny && ny<n)
                        {
                            if (temp == 'B')
                            {
                                if (s[nx][ny] == 'B')
                                {
                                    abnormal[nx][ny] = true;
                                    q.push({nx, ny});
                                }

                            } else {
                                if (s[nx][ny] != 'B')
                                {
                                    abnormal[nx][ny] = true;
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                }
                ans_abnormal++;
            }
        }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> s[i];

    solution(n);

    cout << ans_normal << ' ' << ans_abnormal;

}
