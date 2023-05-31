#include <iostream>
#include <map>
#include <string>

using namespace std;

int t, n;
string name, type;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        map<string, int> m;
        int ans = 1;
        cin >> n;

        while (n--) {
            cin >> name >> type;
            if (m.find(type) == m.end()) m.insert({type, 1});
            else m[type]++;
        }

        for (auto i : m) ans *= (i.second + 1);
        cout << ans - 1 << '\n';
    }
}
