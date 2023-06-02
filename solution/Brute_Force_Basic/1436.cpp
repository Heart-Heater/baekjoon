#include <iostream>
#include <string>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    int temp = 665;
    string s;
    while (n > 0) {
        temp++;
        s = to_string(temp);
        for (int i=0; i<s.length()-2; i++) {
            if (s[i] == '6' && s[i+1] == '6' && s[i+2] == '6') {
                n--;
                break;
            }
        }
    }
    cout << temp;
    return 0;
}
