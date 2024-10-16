#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int r[20] = {0};
int c[20] = {0};
int n, k;

void dfs(int i, int now, int sum)
{
    if (i == n)
    {
        if (sum % k == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << c[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int j = 1; j <= r[i + 1]; j++)
    {
        c[i + 1] = j;
        dfs(i + 1, j, sum + j);
    }
}

void debug()
{
    return;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    dfs(0, 0, 0);
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