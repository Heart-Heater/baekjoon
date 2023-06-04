#include <iostream>
#include <stack>

using namespace std;

int k, x;
stack<int> st;
int result = 0;

int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      cin >> k;

      for (int i=0; i<k; i++) {
            cin >> x;
            if (x != 0) st.push(x);
            else st.pop();
      }
      
      int n = st.size();
      for (int i=0; i<n; i++) {
            result += st.top();
            st.pop();
      }
      cout << result;
}
