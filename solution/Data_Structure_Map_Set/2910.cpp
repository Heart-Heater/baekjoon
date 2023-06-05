#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

map<int, pair<int, int>> m;
int n, c;

bool comp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    if (a.second.first == b.second.first) return a.second.second < b.second.second;
    return a.second.first > b.second.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> c;
    for (int i=0, a; i<n; i++)
    {
        cin >> a;
        auto iter = m.find(a);
        if (iter == m.end()) m.insert({a, {1, i}});
        else m[a].first++;
    }

    vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    for (int i=0; i<v.size(); i++)
    {
        int cnt = v[i].second.first;
        int num = v[i].first;
        while (cnt--)
        {
            cout << num << ' ';
        }
    }

    return 0;
}
