// 1. 절대값을 씌운 1차식들의 합의 최소값을 구하는 수학적인 문제
// 2. 주어진 n이 홀수이면 무조건 최소값을 1개만 가질 수 있음
// 3. n이 짝수일때는 각 식들의 해가 겹치는지 안겹치는지가 중요
// 4. 정렬을 한 뒤 가운데 iterate을 반환하여 한 칸 뒤와 비교했음
// 5. 같으면 최소값은 무조건 1개
// 6. 다르면 두 값 사이의 정수의 개수만큼 최소값을 가질 수 있음

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a, b;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a >> b;
        v.push_back(b - a);
    }

    if (n%2 == 1)
    {
        cout << 1;
        return 0;
    }

    sort(v.begin(), v.end());

    if (v[n/2]==v[n/2-1])
    {
        cout << 1;
        return 0;
    }
    else
    {
        cout << v[n/2] - v[n/2-1] + 1;
        return 0;
    }


}
