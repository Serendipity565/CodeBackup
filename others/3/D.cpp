#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

vector<int> a[200005];
ll ti[200005] = {0};
int c[200005] = {0};

void debug()
{
    return;
}

ll ans = 0;
void dfs(int k)
{
    if (c[k] == 1)
    {
        return;
    }
    else
    {
        ans += ti[k];
        c[k] = 1;
        for (auto x : a[k])
        {
            dfs(x);
        }
    }
    return;
}

void solve()
{
    int n;
    cin >> n;
    int t, k;
    int temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> ti[i] >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> temp;
            a[i].push_back(temp);
        }
    }
    dfs(n);
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}