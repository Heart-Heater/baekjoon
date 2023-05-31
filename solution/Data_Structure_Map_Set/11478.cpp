#include <iostream>
#include <string>
#include <set>

using namespace std;

string s, subs;
int len;
set<string> sets;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    len = s.size();
    for (int i=1; i<=len; i++)
    {
        for (int j=0; j<len-i+1; j++)
        {
            subs = s.substr(j, i);
            sets.insert(subs);
        }

    }
    cout << sets.size();

}
