// 1. 문자열 길이가 10이므로 전부 탐색한다고 해도 10!, 약 360만 정도로 부르트포스로 충분히 가능하다고 생각했음
// 2. 그래도 백트래킹 방법(?)으로 탐색 과정 중 조건에 어긋나면 더이상 탐색하지 않게 하여 시간을 확보했음
// 3. 처음 코드 완성했을 때 첫번째 예제만 답이 다르게 나왔음
// 4. 같은 문자열일지라도 다른 index의 알파벳으로 만들면 카운팅되게 설계되었기때문에 이러한 문제가 발생하는 거였음
// 5. 문자열에 쓰인 알파벳들을 세주어서 각각 팩토리얼들의 곱으로 나누어주어 해결할 수 있었음
// ** 부르트포스와 백트래킹은 DFS 방법을 위주로 작성됨

#include <iostream>
#include <string>

using namespace std;

string s;
bool check[10] = {false, };
int ans, alpha[26]={0, }, denom=1;

void solution(int cnt, char ch, string ss)
{
    if (cnt == 0)
    {
        ans++;
        return;
    }

    for (int i=0; i<ss.size(); i++)
    {
        if (!check[i])
        {
            if (s[i] == ch)
            {
                continue;
            }
            else
            {
                check[i] = true;
                solution(cnt-1, s[i], s);
                check[i] = false;
            }
        }
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    int n = s.size();
    for (int i=0; i<n; i++)
        alpha[s[i]-'a']++;

    for (int i=0; i<26; i++)
        if (alpha[i] != 0)
        {
            for (int j=2; j<=alpha[i]; j++)
                denom *= j;
        }

    solution(n, ' ', s);

    cout << ans/denom;

}
