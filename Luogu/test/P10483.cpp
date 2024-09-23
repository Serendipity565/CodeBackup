#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll c[20] = {0};
ll s[20] = {0};

int mymin = 18;
int n;
ll w;

void dfs(int num, int step)
{
    if (num >= mymin)
    {
        return;
    }
    if (step == n + 1)
    {
        mymin = min(mymin, num);
        return;
    }
    s[num + 1] = c[step];
    dfs(num + 1, step + 1);
    for (int i = 1; i <= num; i++)
    {
        if (s[i] + c[step] <= w)
        {
            s[i] += c[step];
            dfs(num, step + 1);
            s[i] -= c[step];
        }
    }
    return;
}

bool cmp(ll a, ll b)
{
    return a > b;
}

void solve()
{

    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    sort(c + 1, c + 1 + n, cmp);
    dfs(0, 1);
    cout << mymin << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}