#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    string t;
    cin >> s;
    cin >> t;
    if (s == t)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
            {
                if (s[i] == '0')
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    cout << "YES" << endl;
                    return;
                }
            }
            else if (s[i] == t[i] && s[i] == '1')
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
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