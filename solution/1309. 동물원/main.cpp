// 1. DP로 접근
// 2. 점화식을 찾는데 다소 오래 걸렸음. 30분 정도를 점화식 찾는데만 사용
// 3. 코드 자체는 기본적인 bottom-up DP로 전혀 어렵지 않음
// ** 9901로 나눈 나머지를 출력행햐 함. 실수하지 않기

#include <iostream>
#define MAX 100001

using namespace std;

int arr[MAX], n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    arr[1] = 2;
    arr[2] = 6;
    for (int i=3; i<=n; i++)
        arr[i] = (2*arr[i-1] + arr[i-2] + 2)%9901;

    cout << arr[n] + 1;


}
