#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{
    return;
}

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i + 1 < s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            char temp = (s[i] - 'a' + 1) % 26 + 'a';
            s.insert(i + 1, 1, temp);
            cout << s << endl;
            return;
        }
    }
    char temp = (s[0] - 'a' + 1) % 26 + 'a';
    cout << temp << s << endl;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}