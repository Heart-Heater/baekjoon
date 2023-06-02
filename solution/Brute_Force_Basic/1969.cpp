#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m, result;
int dna[50][4];
queue<char> q;

int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      cin >> n >> m;
      string s;
      for (int i=0; i<n; i++) {
            cin >> s;
            for (int j=0; j<m; j++) {
                  char x = s[j];
                  if (x == 'A') dna[j][0]++;
                  else if (x == 'C') dna[j][1]++;
                  else if (x == 'G') dna[j][2]++;
                  else dna[j][3]++;
            }
      }
  
      for (int i=0; i<m; i++) {
            int temp = dna[i][0];
            int pointer = 0;
            for (int j=1; j<4; j++) {
                  if (temp < dna[i][j]) {
                        temp = dna[i][j];
                        pointer = j;
                  }
            }
            if (pointer == 0) q.push('A');
            else if (pointer == 1) q.push('C');
            else if (pointer == 2) q.push('G');
            else q.push('T');
            result += n - temp;
      }

  
      for (int i=0; i<m; i++) {
            cout << q.front();
            q.pop();
      }
      cout << '\n' << result;
  

      
}
