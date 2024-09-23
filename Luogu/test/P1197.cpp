#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
int m;
int k;
int a[400005] = {0};
vector<int> b[400005];
int head[400005] = {0};
int d[400005] = {0};

int find(int x)
{
    if (a[x] == x)
    {
        return x;
    }
    else
    {
        return a[x] = find(a[x]);
    }
}

void check()
{
}

void debug()
{
    return;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
        head[i] = -1;
    }
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        b[x].push_back(y);
        b[y].push_back(x);
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        d[c[i]] = 1;
    }
    int total = n - k;
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