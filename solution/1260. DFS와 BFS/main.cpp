// 1. 기본적인 DFS와 BFS를 공부할 수 있는 문제

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

int n, m, v;
vector<int> graph[MAX];
int visitedDFS[MAX];

void dfs(int start) {
      
      visitedDFS[start] = 1;
      cout << start << ' ';
      for (int i=0; i<graph[start].size(); i++) {
            int y = graph[start][i];
            if (visitedDFS[y] != 1) dfs(y);
      }
      return;
}




void bfs(int start) {
      queue<int> q;
      int visited[MAX] = {0, };
      q.push(start);
      visited[start] = 1;

      while (!q.empty()) {
            int temp = q.front();
            cout << temp << ' ';
            q.pop();
            int tempSize = graph[temp].size();
            for (int i=0; i<tempSize; i++) {
                  int y = graph[temp][i];
                  if (visited[y] != 1) {
                        visited[y] = 1;
                        q.push(y);
                  }
            }
      }
      cout << '\n';
      return;
}


int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      cin >> n >> m >> v;

      
      int x, y;
      for (int i=0; i<m; i++) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
      }

      for (int i=1; i<=n; i++) {
            sort(graph[i].begin(), graph[i].end());
      }

      dfs(v);
      cout << '\n';
      bfs(v);
  
  
}
