#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, ans, check[1001];
string s;
map<string, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> s;
        m.insert({s, i});
    }

    for (int i=1; i<=n; i++)
    {
        cin >> s;
        check[i] = m[s];
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if (check[i] > check[j])
            {
                ans++;
                break;
            }
        }
    }
    cout << ans;

}
