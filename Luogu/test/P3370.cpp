#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

ll ans[10005] = {0};

void debug()
{
    return;
}

ll myhash(string s, ll base, ll mod)
{
    ll hs = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        hs = hs * base + (s[i] - 'a' + 1);
        hs %= mod;
    }
    return hs;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    ll mod = 1e9 + 9;
    ll base = 200;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        ans[i] = myhash(s, base, mod);
    }
    int sum = 0;
    sort(ans + 1, ans + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != ans[i - 1])
        {
            sum++;
        }
    }
    cout << sum << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}