#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll go[100005][40] = {0};
ll sum[100005][40] = {0};
ll mi[100005][40] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    vector<ll> w(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        go[i][0] = a[i];
        sum[i][0] = w[i];
        mi[i][0] = w[i];
    }
    for (int j = 1; j <= 35; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            go[i][j] = go[go[i][j - 1]][j - 1];
            sum[i][j] = sum[i][j - 1] + sum[go[i][j - 1]][j - 1];
            mi[i][j] = min(mi[i][j - 1], mi[go[i][j - 1]][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ll ans_sum = 0;
        ll ans_min = INT64_MAX;
        ll now = i;
        ll steps = k;
        for (int j = 35; j >= 0; j--)
        {
            if ((steps >> j) & 1)
            {
                ans_sum += sum[now][j];
                ans_min = min(ans_min, mi[now][j]);
                now = go[now][j];
            }
        }
        cout << ans_sum << " " << ans_min << endl;
    }
    return 0;
}