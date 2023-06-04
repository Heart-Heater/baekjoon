#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#define MAX 101

using namespace std;

int n, k, d, Time, dead;
int board[MAX][MAX];
deque<pair<int, int>> snake;
int body[MAX][MAX];
queue<pair<int, char>> direction;
int now = 0; // R : 1 / D : 2 / L : 3 / U : 4

void right(int x, int y, int t) {
      int iter = t - Time;
      for (int i=0; i<iter; i++) {
            Time++;
            if (y+1 > n) {
                  dead = 1; break;
            } else if (body[x][y+1] == 1) {
                  dead = 1; break;
            }
            snake.push_front(make_pair(x, y+1));
            body[x][y+1] = 1;
        
            if (board[x][y+1] == 1) board[x][y+1] = 0;
            else {
                  body[snake.back().first][snake.back().second] = 0;
                  snake.pop_back();  
            }
            y++;
      }

}

void left(int x, int y, int t) {
      int iter = t - Time;
      for (int i=0; i<iter; i++) {
            Time++;
            if (y-1 < 1) {
                  dead = 1; break;
            } else if (body[x][y-1] == 1) {
                  dead = 1; break;
            }
            snake.push_front(make_pair(x, y-1));
            body[x][y-1] = 1;
        
            if (board[x][y-1] == 1) board[x][y-1] = 0;
            else {
                  body[snake.back().first][snake.back().second] = 0;
                  snake.pop_back();
            }
            y--;
      }
}

void down(int x, int y, int t) {
      int iter = t - Time;
      for (int i=0; i<iter; i++) {
            Time++;
            if (x+1 > n) {
              dead = 1; break;
            } else if (body[x+1][y] == 1) {
                  dead = 1; break;
            }
            snake.push_front(make_pair(x+1, y));
            body[x+1][y] = 1;
        
            if (board[x+1][y] == 1) board[x+1][y] = 0;
            else {
                  body[snake.back().first][snake.back().second] = 0;
                  snake.pop_back();
            }

            x++;
      }
}

void up(int x, int y, int t) {
      int iter = t - Time;
      for (int i=0; i<iter; i++) {
            Time++;
            if (x-1 < 1) {
                  dead = 1; break;
            } else if (body[x-1][y] == 1) {
                  dead = 1; break;
            }
            snake.push_front(make_pair(x-1, y));
            body[x-1][y] = 1;
            
            if (board[x-1][y] == 1) board[x-1][y] = 0;
            else {
                  body[snake.back().first][snake.back().second] = 0;
                  snake.pop_back();
            }

            x--;
      } 
}


int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
  
      cin >> n >> k;
      int a, b;
      for (int i=0; i<k; i++) {
            cin >> a >> b;
            board[a][b] = 1;
      }
  
      cin >> d;
      int t; char ch;
      for (int i=0; i<d; i++) {
            cin >> t >> ch;
            direction.push(make_pair(t, ch));
      }
  
      direction.push(make_pair(10001, 'D'));
      snake.push_front(make_pair(1, 1));
      body[1][1] = 1;

      int tempD = 0;
      char tempCH;
      for (int i=0; i<d+1; i++) {
            int x = snake.front().first;
            int y = snake.front().second;
        
            tempD = direction.front().first;
            tempCH = direction.front().second;
            direction.pop();

            if (now == 0) right(x, y, tempD);
            else if (now == 1) down(x, y, tempD);
            else if (now == 2) left(x, y, tempD);
            else up(x, y, tempD);
        
            if (dead == 0) {
                  if (tempCH == 'D') {
                        now++;
                        if (now == 4) now = 0;
                  } else {
                        now--;
                        if (now < 0) now = 3;
                  }
            } else break;

      }

      cout << Time;
}
