#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int a[2005][2005] = {0};
int dp[2005][2005] = {0};
int h, w;
bool flag = false;
bool flag2 = false;

void debug()
{
    return;
}

void dfs(int i, int j, int cnt1, int cnt2)
{
    if (flag2)
    {
        return;
    }
    if (i == h && j == w)
    {
        if (cnt1 > cnt2)
        {
            cout << "Takahashi" << endl;
            flag2 = true;
        }
        else if (cnt1 < cnt2)
        {
            flag = true;
        }
        return;
    }
    if (i > h || j > w)
    {
        return;
    }

    if ((i + j) % 2 == 0)
    {
        dfs(i + 1, j, cnt1 + a[i + 1][j], cnt2);
        dfs(i, j + 1, cnt1 + a[i][j + 1], cnt2);
    }
    else
    {
        dfs(i + 1, j, cnt1, cnt2 + a[i + 1][j]);
        dfs(i, j + 1, cnt1, cnt2 + a[i][j + 1]);
    }
}

void solve()
{
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= w; j++)
        {
            if (s[j - 1] == '-')
            {
                a[i][j] = -1;
            }
            else
            {
                a[i][j] = 1;
            }
        }
    }
    // dfs(1, 1, 0, 0);
    // if (flag2)
    // {
    //     return;
    // }
    // if (flag)
    // {
    //     cout << "Aoki" << endl;
    // }
    // else
    // {
    //     cout << "Draw" << endl;
    // }

    for (int i = h; i >= 1; i--)
    {
        for (int j = w; j >= 1; j--)
        {
            if ((i + j) % 2 == 0)
            {
                if (a[i + 1][j] == 0 && a[i][j + 1] == 0)
                {
                    dp[i][j] = 0;
                }
                else if (a[i + 1][j] == 0)
                {
                    dp[i][j] = dp[i][j + 1] + a[i][j + 1];
                }
                else if (a[i][j + 1] == 0)
                {
                    dp[i][j] = dp[i + 1][j] + a[i + 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j] + a[i + 1][j], dp[i][j + 1] + a[i][j + 1]);
                }
            }
            else
            {
                if (a[i + 1][j] == 0 && a[i][j + 1] == 0)
                {
                    dp[i][j] = 0;
                }
                else if (a[i + 1][j] == 0)
                {
                    dp[i][j] = dp[i][j + 1] - a[i][j + 1];
                }
                else if (a[i][j + 1] == 0)
                {
                    dp[i][j] = dp[i + 1][j] - a[i + 1][j];
                }
                else
                {
                    dp[i][j] = min(dp[i + 1][j] - a[i + 1][j], dp[i][j + 1] - a[i][j + 1]);
                }
            }
        }
    }
    if (dp[1][1] > 0)
    {
        cout << "Takahashi" << endl;
    }
    else if (dp[1][1] < 0)
    {
        cout << "Aoki" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }
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