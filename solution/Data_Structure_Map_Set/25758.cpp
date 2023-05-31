#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int n;
string s;
set<string> Set;
set<char> ans;
map<string, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> s;
        if (m.find(s) != m.end()) m[s]++;
        else m.insert({s, 1});

        Set.insert(s);
    }

    for (auto o=Set.begin(); o!=Set.end(); o++)
    {
        string a = *o;

        if (m[a] > 1)
        {
            if (a[0] <= a[1]) ans.insert(a[1]);
            else ans.insert(a[0]);
        }

        for (auto oo=Set.upper_bound(a); oo!=Set.end(); oo++)
        {
            string b = *oo;
            if (a[0] <= b[1]) ans.insert(b[1]);
            else ans.insert(a[0]);

            if (b[0] <= a[1]) ans.insert(a[1]);
            else ans.insert(b[0]);

        }

    }
    cout << ans.size() << '\n';
    for (auto it=ans.begin(); it!=ans.end(); it++)
    {
        if (it==ans.begin()) cout << *it;
        else cout << ' ' << *it;
    }

}
