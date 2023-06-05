#include <iostream>
#include <map>

using namespace std;

int n, m;
map<int, int> cards;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0, a; i<n; i++)
    {
        cin >> a;
        if (cards.find(a) == cards.end())
            cards.insert({a, 1});
        else
            cards[a]++;
    }

    cin >> m;
    for (int i=0, a; i<m; i++)
    {
        cin >> a;
        auto iter = cards.find(a);
        if (iter == cards.end()) cout << 0 << ' ';
        else cout << iter->second << ' ';
    }
    return 0;
}
