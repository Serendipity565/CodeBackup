#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

void debug()
{
    return;
}

vector<ll> a[1000006];
map<ll, ll> mp;
ll inv[1000006] = {0};

ll fast_pow(ll a, ll b, ll c)
{
    ll ans = 1;
    a %= c;
    while (b) // 不能写成b>1，否则会出问题！！！
    {
        if (b % 2 == 1) // 可以用b&1进行更快的判断
        {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b /= 2; // 可以用b>>=1来代替
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        ll temp;
        for (int j = 1; j <= k; j++)
        {
            cin >> temp;
            a[i].push_back(temp);
            mp[temp]++;
        }
    }
    for (int i = 1; i <= 1000004; i++)
    {
        inv[i] = fast_pow(i, mod - 2, mod);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto x : a[i])
        {
            // ll temp = (inv[n] % mod * inv[a[i].size()]) % mod;
            // ll temp2 = ((mp[x] % mod) * inv[n]) % mod;
            // ans += (temp * temp2) % mod;
            ans += (((inv[n] * inv[a[i].size()]) % mod) * (((mp[x] % mod) * inv[n]) % mod)) % mod;
            ans %= mod;
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

    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
