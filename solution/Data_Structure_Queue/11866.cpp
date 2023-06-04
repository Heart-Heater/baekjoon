#include <iostream>
#include <queue>

using namespace std;

int n, k, curr=1;
queue<int> q, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<n; i++) q.push(i+1);

    while (1) {
        if (q.size() == 0) break;

        if (curr != k) {
            int a = q.front();
            q.pop();
            q.push(a);
            curr++;
        } else {
            result.push(q.front());
            q.pop();
            curr = 1;
        }
    }

    if (n == 1) {
        cout << '<' << result.front() << '>';
    } else {
        for (int i=0; i<n; i++) {
            if (i==0) {
                cout << '<' << result.front() << ", ";
                result.pop();
            } else if (i ==  n-1) {
                cout << result.front() << '>';
                result.pop();
            } else {
                cout << result.front() << ", ";
                result.pop();
            }
        }

    }


}
