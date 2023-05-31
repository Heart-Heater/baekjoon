#include <iostream>
#include <string>
#include <set>

using namespace std;

int r, c, up, down,mid;
string s, arr[1001];
bool check;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    for (int i=1; i<=r; i++)
    {
        cin >> s;
        arr[i] = s;
    }

    int down = r, up = 1;

    while (down>=up)
    {
        mid = (down+up)/2;
        set<string> Set;

        for (int i=0; i<c; i++)
        {
            string tmp = "";
            for (int j=mid; j<=r; j++)
            {
                tmp += arr[j][i];
            }
            Set.insert(tmp);
        }


        if (Set.size() != c)
        {
            down = mid-1;
            check = true;
        }
        else
        {
            up = mid+1;
            check = false;
        }


    }
    if (check) cout << mid - 2;
    else cout << mid - 1;

}
