// 15649번 문제와의 차이점은 중복이 없어야 한다는 점과 오름차순으로 출력되어야 한다는 점

#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = {0, };

void backTracking(int now, int cnt)
{
    if (cnt == m) {
        for (int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=now; i<=n; i++) {
        arr[cnt] = i;
        backTracking(i+1, cnt+1);

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    backTracking(1, 0);

    return 0;
}
