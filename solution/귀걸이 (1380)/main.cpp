// 1. 문자열 다루는 간단한 문제
// ** cin과 getline을 함께 쓸 때는 주의해야함 (이것때문에 오래 걸림)
// cin >> n;  이를 해결하기 위해 cin.ignore() 라는 함수를 사용
// geline(cin, s);
// 위 코드대로 하면 getline을 실행하지 않고 넘어감.
// 이유는 버퍼에 정수 값을 입력한 뒤 누른 엔터(‘\n’)가 그대로 남아있어 getline()에 들어가기 때문이다.
// cin.ignore(); 을 추가하여 버퍼를 비워줘야 정상적으로 동작.


#include <iostream>
#include <string>

using namespace std;

string s[101], ans;
int n = 1, a, case_num;
char b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (1)
    {
        case_num++;

        cin >> n;
        cin.ignore();
        int check[n+1] = {0, };

        if (n == 0) break;

        for (int i=1; i<=3*n-1; i++)
        {
            if (i<=n)
            {
                getline(cin, s[i]);
            }
            else
            {
                cin >> a >> b;
                check[a]++;
            }
        }


        for (int i=1; i<=n; i++)
        {
            if (check[i] != 2)
                ans = s[i];
        }

        cout << case_num << ' ' << ans << '\n';

    }
}
