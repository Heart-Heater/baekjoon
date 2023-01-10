// 1. 플로이드 워셜 알고리즘을 공부할 수 있는 문제
// 2. 배열을 0이 아닌 값으로 초기화할 때 fill 함수를 사용하는 방법을 배움
// 3. 이 문제는 모든 거리가 1이지만 각 노드별 간선마다 거리가 달라지는 문제에서 일반적으로 사용되는 듯
// 4. 플로이드 워셜 알고리즘은 3중 반복문으로 O(N^3)
// ** 비교적 느린 알고리즘인듯. 주어진 N의 크기와 제한시간에 유념하자.

#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, m, graph[101][101], ans[101] = {0, };

int main(void) {
    cin >> n >> m;

    for (int i=0; i<101; i++)
    {
        fill(graph[i], graph[i] + 101, INF);
    }

    // 자기 자신으로 가는 거리는 0으로 초기화
    for (int a=1; a<=n; a++)
    {
        for (int b=1; b<=n; b++)
        {
            if (a == b) graph[a][b] = 0;
        }
    }

    // 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
    // 이 문제에서는 거리는 모두 1로 동일
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1; // 방향성이 없기 때문에 대칭적으로 넣어줌
    }

    // 플로이드 워셜 알고리즘을 수행
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            ans[i] += graph[i][j];
        }

    int min_ = *min_element(ans+1, ans+n+1);
    for (int i=1; i<=n; i++)
        if (ans[i]==min_)
        {
            cout << i;
            return 0;
        }
}
