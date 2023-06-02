#include <iostream>

using namespace std;

int n, x, y, cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x >> y;

    if (x > y) {
        int a;
        a = x;
        x = y;
        y = a;
    }

    while (n>1) {

        if (y-x == 1 && x%2 == 1) {
            cnt++;
            break;
        }

        if (n%2 == 1) n = n/2 + 1;
        else n /= 2;

        if (x%2 == 0) x /= 2;
        else x = x/2 + 1;

        if (y%2 == 0) y /= 2;
        else y = y/2 + 1;

        cnt++;


    }
    cout << cnt;

}
