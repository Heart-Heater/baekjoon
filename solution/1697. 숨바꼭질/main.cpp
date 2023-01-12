// 1. BFS로 최단 경로를 찾는문제
// 2. 처음에는 모든 점들을 연결해주는 graph vector 객체를 만들어주려고 했는데 생각해보니 굳이 그럴 필요가 없었음
//    이런 문제의 경우 graph를 만드는 것은 시간 낭비. 바로 bfs 안에서 해결 가능했음
// 3. 공부하는 과정 중에 BFS와 다익스트라의 차이점에 대해서 알게 되었음
//    BFS는 가중치가 없는 간선에서 최단 거리를 찾는 경우 / 다익스트라는 가중치가 다르고 음수가 없는 경우에 사용한다고 함
// ** 참고 : https://velog.io/@kasterra/%ED%95%B5%EC%8B%AC-%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EA%B7%B8%EB%9E%98%ED%94%84-%EC%B5%9C%EB%8B%A8-%EA%B2%BD%EB%A1%9C-%ED%83%90%EC%83%89
// *** 음수 간선이 있을 때 벨만 포드 알고리즘, 모든 경로 플로이드 워셜 등 더 공부할 필요가 있음

#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int n, k, dist[MAX];
bool visited[MAX] = {false, };

void bfs(int start)
{
    queue<int> q;
    visited[start] = true;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int temp = q.front();

        if (temp == k)
            break;
        q.pop();

        if (temp+1<MAX && !visited[temp+1])
        {
            visited[temp+1] = true;
            q.push(temp+1);
            dist[temp+1] = dist[temp]+1;
        }

        if (temp-1>=0 && !visited[temp-1])
        {
            visited[temp-1] = true;
            q.push(temp-1);
            dist[temp-1] = dist[temp]+1;
        }

        if (2*temp<MAX && !visited[2*temp])
        {
            visited[2*temp] = true;
            q.push(2*temp);
            dist[2*temp] = dist[temp]+1;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    bfs(n);

    cout << dist[k];
}
