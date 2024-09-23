#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll s[100005] = {0};
ll a[100005] = {0};
ll f[100005][30] = {0};

void pre()
{
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i <= 100004; i++)
    {
        a[i] = a[i / 2] + 1;
    }
    return;
}

void debug()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void solve()
{
    int n;
    ll m;
    pre();
    cin >> n >> m;
    ll mymin = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> f[i][0];
        s[i] += s[i - 1];
        mymin = max(mymin, f[i][0]);
    }
    // debug();
    for (int j = 1; j <= 25; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    // debug();
    int j = 1;
    for (int i = 0; i < n; i++)
    {
        while (j <= n && s[j] - s[i] < m)
        {
            j++;
        }
        if (s[j] - s[i] >= m)
        {
            int q = a[j - i];
            mymin = min(mymin, max(f[i + 1][q], f[j - (1 << q) + 1][q]));
        }
    }
    cout << mymin << endl;
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