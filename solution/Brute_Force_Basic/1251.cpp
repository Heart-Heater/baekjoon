#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, temp, ans, comp;
int check[51];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    int n = s.size();

    ans = "";
    for (int i=0; i<n-2; i++)
        for (int j=i+1; j<n-1; j++)
            for (int k=j+1; k<n; k++)
            {
                string comp;
                temp = s.substr(0, i+1);
                reverse(temp.begin(), temp.end());
                comp += temp;

                temp = s.substr(i+1, j-i);
                reverse(temp.begin(), temp.end());
                comp += temp;

                temp = s.substr(j+1, n-j-1);
                reverse(temp.begin(), temp.end());
                comp += temp;

                if (ans == "")
                    ans = comp;
                else if (ans.compare(comp) > 0)
                    ans = comp;

            }

    cout << ans;

}
