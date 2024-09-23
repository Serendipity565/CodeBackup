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
    string t;
    ll ans = 0;
    cin >> s;
    cin >> t;
    for (int i = 0; i < s.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i + j] != t[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _;
    _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}