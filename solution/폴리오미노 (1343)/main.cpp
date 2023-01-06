// 1. 그리디 문제로 접근했음
// 2. X의 개수가 홀수면 -1 출력 후 return
// 3. X의 개수가 짝수면 4의 배수 만큼 AAAA 출력 후 나머지 있으면 BB 

#include <iostream>
#include <string>

using namespace std;

string s;
int check;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    int n = s.size();

    string ans = "";
    for (int i=0; i<n; i++)
    {
        char temp = s[i];

        if (temp == 'X')
        {
            check++;
            if (i == n-1)
            {
                if (check%2 == 1)
                {
                    cout << -1;
                    return 0;
                }
                else if (check == 2)
                    ans += "BB";
                else if (check >= 4)
                {
                    int A_cnt = check/4;
                    int B_cnt = check%4;
                    for (int j=0; j<A_cnt; j++)
                        ans += "AAAA";
                    if (B_cnt != 0)
                        ans += "BB";
                }
            }
        }
        else
        {
            if (check%2 == 1)
            {
                cout << -1;
                return 0;
            }
            else if (check == 2)
                ans += "BB";
            else if (check >= 4)
            {
                int A_cnt = check/4;
                int B_cnt = check%4;
                for (int j=0; j<A_cnt; j++)
                    ans += "AAAA";
                if (B_cnt != 0)
                    ans += "BB";
            }

            ans += ".";
            check = 0;

        }

    }
    cout << ans;

}
