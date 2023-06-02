// 1. DFS를 이용한 부르트포스로 접근하여 풀었음
//    처음에는 vector에 결과값들을 넣은 다음 최종적으로 sort하려 했지만
//    생각해보니 굳이 그럴 필요없이 input 받은 arr를 처음부터 sort하면 더 쉽다는 것을 깨달음

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
char arr[16];
bool visited[16] = {false, };
vector<string> result;

void dfs(string now, int before, int consonants, int vowels)
{
    if (now.size() == l)
    {
        if (vowels>=1 && consonants >= 2)
        {
            cout << now << '\n';
            return;
        }


    }

    for (int i=1; i<=c; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            char temp = arr[i];
            if (temp-'0' > before)
            {
                if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
                    dfs(now+temp, temp-'0', consonants, vowels+1);
                else
                    dfs(now+temp, temp-'0', consonants+1, vowels);
            }
            visited[i] = false;

        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> l >> c;
    for (int i=1; i<=c; i++)
    {
        char ch;
        cin >> ch;
        arr[i] = ch;
    }

    sort(arr+1, arr+c+1);
    dfs("", -1, 0, 0);

}
