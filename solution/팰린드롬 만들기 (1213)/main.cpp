// 1. map을 이용하여 unique한 알파벳을 뽑아낸 후
// 2. 그들의 개수로 접근
// 3. 문자열 길이가 짝수일 때 하나라도 홀수개인 알파벳이 있으면 불가능
// 4. 문자열 길이가 홀수일 때는 반드시 하나의 알파벳만 홀수개여야함
// 5. 홀수개인 알파벳이 두 개 이상이 되는 순간 불가능.
// ** reverse 함수는 void 함수로 초기화와 함께 사용할 수 없음. 계속 실수하는 부분.
// ** 문제 구분은 그리디. 그리디하게 푸는 방법도 생각해보기.

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string s, ans, temp = "";
map<char, int> m;
int odd_cnt, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    for (int i=0; i<s.size(); i++)
    {
        char& ch = s[i];
        if (m.find(ch) != m.end())
            m[ch]++;
        else
            m.insert({ch, 1});
    }

    n = s.size();
    ans = "";
    if (n%2!=0)
    {
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            int cnt = it->second;
            if (cnt%2 != 0)
            {
                if (odd_cnt==0)
                {
                    cnt--; odd_cnt++;
                    temp = it->first;
                }
                else
                {
                    cout << "I'm" << ' ' << "Sorry" << ' ' << "Hansoo";
                    return 0;
                }

            }


            for (int i=0; i<cnt/2; i++)
                ans += it->first;

        }
    }
    else
    {
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            int cnt = it->second;

            if (cnt%2 != 0)
            {
                cout << "I'm " << "Sorry " << "Hansoo";
                return 0;
            }

            for (int i=0; i<cnt/2; i++)
                ans += it->first;

        }
    }


    string rev_ans = ans;
    reverse(rev_ans.begin(), rev_ans.end());
    ans += temp;
    cout << ans+rev_ans;


}
