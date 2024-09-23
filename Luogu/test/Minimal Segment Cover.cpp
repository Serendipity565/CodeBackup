#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int f[500005][25] = {0};

int n, m;
int maxr = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, r;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        f[l][0] = max(f[l][0], r);
        maxr = max(maxr, r);
    }
    for (int i = 1; i <= maxr; i++)
    {
        if (f[i - 1][0] >= i)
        {
            f[i][0] = max(f[i - 1][0], f[i][0]);
        }
    }

    for (int i = 1; i <= 22; i++)
    {
        for (int j = 0; j <= maxr; j++)
        {
            f[j][i] = f[f[j][i - 1]][i - 1];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        int ans = 0;
        for (int j = 22; j >= 0; j--)
        {
            if (f[l][j] < r)
            {
                l = f[l][j];
                ans += 1 << j;
            }
        }
        if (f[l][0] >= r)
        {
            cout << ans + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}