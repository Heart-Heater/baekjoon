#include <iostream>
#include <string>

using namespace std;

int n, result;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    if (n == 1000) n--;

    for (int i=1; i<=n; i++) {
        if (i<100) result++;
        else {
            s = to_string(i);
            if (s[0]-s[1] == s[1]-s[2]) result++;
        }
    }
    cout << result;
}
