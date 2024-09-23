#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void debug()
{
    return;
}

void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> mp1, mp2, mp3, mp4;

    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        mp1[x]++;
        mp2[y]++;
        mp3[y - x]++;
        mp4[x + y]++;
    }
    ll ans = 0;
    for (auto i : mp1)
    {
        ans += i.second * (i.second - 1);
    }
    for (auto i : mp2)
    {
        ans += i.second * (i.second - 1);
    }
    for (auto i : mp3)
    {
        ans += i.second * (i.second - 1);
    }
    for (auto i : mp4)
    {
        ans += i.second * (i.second - 1);
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}