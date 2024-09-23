#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

struct P1111
{
    int u, v;
    int time;
} a[100005];
int b[1004] = {0};
int n, m;

bool cmp(P1111 a1, P1111 a2)
{
    return a1.time < a2.time;
}

int find(int x)
{
    if (b[x] == x)
    {
        return x;
    }
    else
    {
        return b[x] = find(b[x]);
    }
}
void debug()
{

    return;
}

bool check()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == i)
        {
            sum++;
        }
        if (sum >= 2)
        {
            return false;
        }
    }
    return true;
}

void solve()
{

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].time;
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = i;
    }
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int fx = find(a[i].u);
        int fy = find(a[i].v);
        b[fx] = fy;
        if (check())
        {
            cout << a[i].time << endl;
            return;
        }
    }

    cout << -1 << endl;
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
