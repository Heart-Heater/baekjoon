#include <iostream>
#include <stack>
#include <string>

using namespace std;

int t;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> s;
        stack<char> st;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') st.push(s[i]);
            else {
                if (st.empty()) st.push(s[i]);
                else if (st.top() == '(') st.pop();
                else st.push(s[i]);
            }
        }
        if (st.size() == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
