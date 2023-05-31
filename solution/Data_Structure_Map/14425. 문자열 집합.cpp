#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m, ans;
string s;
map<string, bool> Map;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    while (n--) {
        cin >> s;
        Map.insert({s, true});
    }
    while (m--) {
        cin >> s;
        if (Map[s]==true) ans++;
    }
    cout << ans;
}
