#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
stack<int> st;
vector<int> result;
stack<int> compare;

int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      cin >> n; int x;
      for (int i=0; i<n; i++) {
            cin >> x;
            st.push(x);
      }
  
      int temp = st.top();
      st.pop();
      result.push_back(-1);
      for (int i=1; i<n; i++) {
            int y = st.top();
            st.pop();
            if (y < temp) {
                  result.push_back(temp);
                  compare.push(temp);
            } else if (y == temp) {
                  result.push_back(result.back());
            } else {
                  if (result[i-1] == -1) {
                        result.push_back(-1);
                        while (!compare.empty()) compare.pop();
                  } else {
                        while (!compare.empty()) {
                              int cmp = compare.top();
                              if (y < cmp) {
                                    result.push_back(cmp);
                                    break;
                              }
                              compare.pop();
                        }
                        if (compare.empty()) result.push_back(-1);
                  }
            }
            temp = y;
      }

      for (int i=n-1; i>=0; i--) {
            cout << result[i] << ' ';
      }
  
}
