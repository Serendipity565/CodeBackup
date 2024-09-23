#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll h[200005] = {0};
ll pw[200005] = {0};

void myhash(const string &s, ll base, ll mod)
{
    ll hs = 0;
    pw[0] = 1;
    for (ll i = 0; i < s.size(); ++i)
    {
        hs = (hs * base + (s[i] - 'a' + 1)) % mod;
        pw[i + 1] = (pw[i] * base) % mod;
        h[i + 1] = hs;
    }
}

ll getsub(int l, int r)
{
    ll len = r - l + 1;
    return (h[r + 1] - (h[l] * pw[len]) % mod + mod) % mod;
}

void solve()
{
    ll base = 31;
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    myhash(s, base, mod);
    ll l, r;
    for (ll i = 0; i < q; i++)
    {
        cin >> l >> r;
        l--;
        r--;
        if ((r - l + 1) % 2 != 0)
        {
            cout << "No" << endl;
            continue;
        }
        ll mid = (r + l) / 2;
        ll lh = getsub(l, mid);
        ll rh = getsub(mid + 1, r);
        if (lh == rh)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
