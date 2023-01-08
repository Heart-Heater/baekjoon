// 1. 문자열 구현 간단한 문제였음
// 2. 문자열에 새로운 문자 삽입할 때 s.insert(index, "") 기억하기
// ** e.g. s = "ABE"; s.insert(2, "CD") = "ABCDE"
// *** 반드시 큰따옴표 
// **** cin과 getline을 함께 사용할 때는 반드시 cin.ignore() 사용하기

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
bool alpha[26];
string s, ans[30];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin.ignore();
    for (int j=0; j<n; j++)
    {
        getline(cin, s);
        int len = s.size();
        bool check = false;
        vector<int> v;
        v.push_back(-1);

        for (int i=0; i<len; i++)
        {
            if (s[i] == ' ')
                v.push_back(i);
        }
        for (auto num : v)
        {
            char& temp = s[num+1];
            if ('a' <= temp && temp <= 'z')
            {
                if (!alpha[temp-'a'])
                {
                    alpha[temp-'a'] = true;
                    s.insert(num+1, "[");
                    s.insert(num+3, "]");
                    check = true;
                    break;
                }
                else
                    continue;
            }
            else if ('A' <= temp && temp <= 'Z')
            {
                if (!alpha[temp-'A'])
                {
                    alpha[temp-'A'] = true;
                    s.insert(num+1, "[");
                    s.insert(num+3, "]");
                    check = true;
                    break;
                }
            else
                continue;
            }
        }

        if (!check)
        {
            for (int i=1; i<len; i++)
            {
                char& temp = s[i];
                if ('a' <= temp && temp <= 'z')
                {
                    if (!alpha[temp-'a'])
                    {
                        alpha[temp-'a'] = true;
                        s.insert(i, "[");
                        s.insert(i+2, "]");
                        check = true;
                        break;
                    }
                    else
                        continue;
                }
                else if ('A' <= temp && temp <= 'Z')
                {
                    if (!alpha[temp-'A'])
                    {
                        alpha[temp-'A'] = true;
                        s.insert(i, "[");
                        s.insert(i+2, "]");
                        check = true;
                        break;
                    }
                    else
                        continue;
                }

            }
        }

        ans[j] = s;
    }

    for (int i=0; i<n; i++)
        cout << ans[i] << '\n';

}
