#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n, k, SA, SB;
    cin >> n >> k >> SA >> SB;
    vector<int> a(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    auto check = [&](int S)
    {
        vector<int> vis(n + 1, 0);
        int pos = S, cnt = k;
        ll max_x = 0, pre_sum = 0;
        do
        {
            vis[pos] = 1;
            cnt--;
            pre_sum += 1ll * a[pos];
            ll now = pre_sum + 1ll * a[pos] * cnt;
            max_x = max(max_x, now);
            pos = p[pos];
        } while (vis[pos] == 0 && cnt > 0);
        return max_x;
    };
    auto A = check(SA);
    auto B = check(SB);
    if (A > B)
        cout << "Bodya\n";
    else if (A < B)
        cout
            << "Sasha\n";
    else
        cout << "Draw\n";
}

int main()
{
    // freopen("D.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}