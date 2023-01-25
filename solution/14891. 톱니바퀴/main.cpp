// 1. 간단한 구현 문제. 조건별로 나누어서 코드를 나누어 짰음
// ** 조건별로 나누지 않고 한번에 처리할 수 있는 방법이 있는지 좀더 고민해봐야함
// 
// idea : 각 문자열의 3번째와 7번째(string 내에서는 2, 6번째)를 매번 확인하여 극이 다른지 체크했음
//        1번부터 4번까지 톱니바퀴를 돌리는 경우를 나누어서 해당 경우에 맞게 

#include <iostream>
#include <string>

using namespace std;

int k, which, dir, ans;
bool check[4] = {false, };
int score[5] = {0, 1, 2, 4, 8};
string s[5];


string rotation(string s, int dir)
{
    if (dir == 1)
    {
        string push = s.substr(0, 7);
        return s[7] + push;
    }
    else
    {
        string pull = s.substr(1, 7);
        return pull + s[0];
    }

}

void checking()
{
    for (int i=1; i<=3; i++)
    {
        if (s[i][2] == s[i+1][6])
            check[i] = true;
        else
            check[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i=1; i<=4; i++)
        cin >> s[i];

    cin >> k;
    while (k--)
    {
        cin >> which >> dir;

        checking();
        if (which == 1)
        {
            s[1] = rotation(s[1], dir);
            for (int i=1; i<=3; i++)
            {
                if (!check[i])
                {
                    s[i+1] = rotation(s[i+1], -dir);
                    dir = -dir;
                }
                else
                    break;
            }
        }
        else if (which == 2)
        {
            s[2] = rotation(s[2], dir);
            if (!check[1])
                s[1] = rotation(s[1], -dir);
            for (int i=2; i<=3; i++)
            {
                if (!check[i])
                {
                    s[i+1] = rotation(s[i+1], -dir);
                    dir = -dir;
                }
                else
                    break;
            }
        }
        else if (which == 3)
        {
            s[3] = rotation(s[3], dir);
            if (!check[3])
                s[4] = rotation(s[4], -dir);
            for (int i=2; i>=1; i--)
            {
                if (!check[i])
                {
                    s[i] = rotation(s[i], -dir);
                    dir = -dir;
                }
                else
                    break;
            }
        }
        else
        {
            s[4] = rotation(s[4], dir);
            for (int i=3; i>=1; i--)
            {
                if (!check[i])
                {
                    s[i] = rotation(s[i], -dir);
                    dir = -dir;
                }
                else
                    break;
            }
        }

    }

    for (int i=1; i<=4; i++)
    {
        if (s[i][0] == '0')
            continue;
        else
            ans += score[i];
    }

    cout << ans;
}
