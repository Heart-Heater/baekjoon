#include <iostream>
#include <vector>
#define maxScore 2000

using namespace std;

const int MAX = 21;
int n, total;
int result = maxScore;
int arr[MAX][MAX];


int dfs(int n, int r, vector<int> start, int index, int depth) {

      if (r == 0) {
            int temp = 0;
            bool linkCheck[MAX] = {false};
            for (int i=0; i<n/2; i++) {
                  for (int j=0; j<n/2; j++) {
                        temp += arr[start[i]][start[j]];
                  }
                  linkCheck[start[i]] = true;
            }
            vector<int> link;
            for (int i=0; i<n; i++) {
                  if (!linkCheck[i+1]) link.push_back(i+1);
            }
            int temp2 = 0;
            for (int i=0; i<n/2; i++) {
                  for (int j=0; j<n/2; j++) {
                        temp2 += arr[link[i]][link[j]];
                  }
            }
            
            temp = temp - temp2;
            if (temp < 0) temp = -temp;
            result = min(result, temp);
      } else if (depth == n) {
            return 0;
      } else {
            start[index] = depth + 1;
            dfs(n, r-1, start, index+1, depth+1);
            dfs(n, r, start, index, depth+1);
      }

      return result;
  
}

int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      cin >> n;
      vector<int> start(n/2);
  
      int x;
      for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                  cin >> x;
                  arr[i][j] = x;
                  total += x;
            }
      }

      cout << dfs(n, n/2, start, 0, 0);
  
  
}
