#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#if LOCAL
#include "debug.h"
#else
#define debug(...) 114514
#endif

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int bit = 0; bit < 22; ++bit)
    {
        int cnt1 = 0, cnt0 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] & (1 << bit))
                cnt1++;
            else
                cnt0++;
        }
        ans += (cnt1 * (cnt1 - 1) / 2 + cnt1 * cnt0) * (1 << bit);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}