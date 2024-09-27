#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int a[100005] = {0};

void debug()
{
    return;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll cnt = 0;

    if (x == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cnt += (mp[x ^ a[i]] - 1);
        }
        cout << cnt / 2 << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        cnt += mp[x ^ a[i]];
    }
    cout << cnt / 2 << endl;
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