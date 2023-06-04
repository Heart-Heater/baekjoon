#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = {0, };
bool visited[MAX] = {0, };

void backTracking(int cnt)
{
    if (cnt == m) {
        for (int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = i;
            backTracking(cnt+1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    backTracking(0);
    return 0;
}
