#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int p[10005] = {0};
int c[10005] = {0};
int t[10005] = {0};
int dp[1500] = {0};

void solve()
{
    int x1, y1, x2, y2;
    scanf("%d:%d %d:%d", &x1, &y1, &x2, &y2);
    if (y1 > y2)
    {
        y2 += 60;
        x2--;
    }
    int m = (x2 - x1) * 60 + y2 - y1;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &t[i], &c[i], &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 0)
        {
            for (int j = t[i]; j <= m; j++)
            {
                dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
            }
        }
        else
        {
            for (int k = 1; k <= p[i]; k++)
            {
                for (int j = m; j >= t[i]; j--)
                {
                    dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
                }
            }
        }
    }
    printf("%d\n", dp[m]);
    // cout << dp[m] << endl;
}

int main()
{
    /*
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    */
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}