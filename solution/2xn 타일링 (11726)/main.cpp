// 1. DP로 접근
// 2. 수가 매우 커지기 때문에 매 시행마다 10007로 나누어줌
// 3. 나머지의 덧셈 연산은 나눗셈에 영향을 받지 않음

#include <iostream>

using namespace std;

int n, arr[1001];

int dp(int n)
{
    if (n==1) return 1;
    if (n==2) return 2;

    if (arr[n] > 0)
        return arr[n];

    arr[n] = (dp(n-1) + dp(n-2))%10007;
    return arr[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    cout << dp(n);
}
