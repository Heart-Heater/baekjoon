// 1. 부르트 포스로 풀 수 있었음
// 2. 처음에는 가능한 범위에서 재귀를 이용한 부르트포스를 사용하려 했는데 시간초과가 떴음
//    단순히 전체 범위에서 반복문을 쓰는 것이 더 오래 걸릴 것이라고 생각했지만 아니었음
//    범위가 단축되어도 재귀함수 자체가 적용되는데 시간이 오래 걸리나봄

#include <iostream>
#include <string>
#define MAX 500001

using namespace std;

int m, ans = MAX;
string n;
bool number[10] = {false, };

bool check(string &s)
{
    for (int i=0; i<s.size(); i++)
    {
        if (number[s[i]-'0'])
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int a;
        cin >> a;
        number[a] = true;
    }

    ans = min(ans, abs(stoi(n)-100));

    string temp;
    for (int i=0; i<=1000000; i++)
    {
        temp = to_string(i);
        if (check(temp))
        {
            int x = abs(i-stoi(n))+temp.size();
            ans = min(ans, x);
        }
    }

    cout << ans;



}
