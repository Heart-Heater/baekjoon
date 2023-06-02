#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    int x, y;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    for (int i=0; i<n; i++) {
        int cnt = 0;
        for (int j=0; j<n; j++) {

            if (v[i].first >= v[j].first) continue;
            else {
                if (v[i].second < v[j].second) cnt++;
            }

        }
        result.push_back(cnt+1);
    }

    for (int i=0; i<result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}
