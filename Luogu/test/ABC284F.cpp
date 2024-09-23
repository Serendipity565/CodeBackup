#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

ll base = 29;
ll mod = 1000000007;
ll Hashf[10000010];
ll pos[10000010];
ll Hashb[10000010];

void debug()
{
    return;
}

ll suml(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    return ((Hashf[r] - (Hashf[l - 1] * pos[r - l + 1]) % mod) + mod) % mod;
}

ll sumr(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    return ((Hashb[r] - (Hashb[l - 1] * pos[r - l + 1]) % mod) + mod) % mod;
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
    string s;
    cin >> n;
    cin >> s;
    s = " " + s;
    pos[0] = 1;
    for (int i = 1; i <= 2 * n; i++)
    {
        pos[i] = pos[i - 1] * base % mod;
        Hashf[i] = (Hashf[i - 1] * base % mod + (s[i] - 'a')) % mod;
        Hashb[i] = (Hashb[i - 1] * base % mod + (s[2 * n - i + 1] - 'a')) % mod;
    }
    for (int i = 0; i <= n; i++)
    {
        if ((i == 0 || suml(1, i) == sumr(n - i + 1, n)) && (i == n || suml(i + n + 1, 2 * n) == sumr(n + 1, n * 2 - i)))
        {
            cout << s.substr(1, i) + s.substr(i + n + 1, n - i) << endl;
            cout << i;
            return;
        }
    }
    cout << -1 << endl;
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