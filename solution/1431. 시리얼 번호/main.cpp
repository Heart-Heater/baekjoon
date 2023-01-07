// 1. 단순 정렬 문제
// 2. 비교 기준을 새롭게 정의하는 방법을 다시 복습할 수 있었던 문제

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string s[50];


bool comp(string s1, string s2)
{
    if (s1.size() != s2.size())
        return s1.size() < s2.size();

    int sum_s1 = 0;
    int sum_s2 = 0;
    for (int i=0; i<s1.size(); i++)
    {
        if ('0' <= s1[i] && s1[i] <= '9')
            sum_s1 += s1[i] - '0';
        if ('0' <= s2[i] && s2[i] <= '9')
            sum_s2 += s2[i] - '0';
    }

    if (sum_s1 != sum_s2)
        return sum_s1 < sum_s2;

    return s1 < s2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> s[i];

    sort(s, s+n, comp);
    for (int i=0; i<n; i++)
        cout << s[i] << '\n';
}
