#include <iostream>
#include <stack>
 
using namespace std;

stack<pair<int, int> > s; 
int n, h;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
 
    for (int i = 0; i < n; i++) {
          cin >> h;
 
          while (!s.empty()) {
                if (h < s.top().second) { 
                      cout << s.top().first << " ";
                      break;
                }
                s.pop();
          }
          if (s.empty()) cout << 0 << " ";
          s.push(make_pair(i + 1, h));
    }

}  
