// 1. 처음에 DP로 접근하려고 했음
// 2. 풀다보니 DP로 하지 않아도 됨을 깨달음
// 3. 재귀적으로 풀 수 있었음
// ** 이 문제에서는 사용하지 않았지만 for문에서 iter를 iter++ 외에도 다양하게 증가시킬 수 있음
// *** e.g. (int i=0; i<n; i=i+2) or (int i=0; i<n; i=3*i)

#include <iostream>
#include <vector>

using namespace std;

int n, r, c, ans;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> r >> c;

    while (n--)
    {
        int half = 1;
        for(int i=0; i<n; i++)
            half *= 2;
        if (r < half && c < half)
            v.push_back(0);
        else if (r < half && c >= half)
        {
            v.push_back(1);
            c -= half;
        }
        else if (r >= half && c < half)
        {
            v.push_back(2);
            r -= half;
        }
        else
        {
            v.push_back(3);
            c -= half;
            r -= half;
        }

    }

    int v_size = v.size();
    int i = 1;
    while (v.size())
    {
        int temp = v.back();
        v.pop_back();
        ans += i*temp;
        i *= 4;
    }

    cout << ans;
}
