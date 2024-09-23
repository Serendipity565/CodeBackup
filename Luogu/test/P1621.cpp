#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int f[100005] = {0};
bool vis[100005] = {0};

void pre(int n)
{
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
}

int find(int x)
{
    if (f[x] == x)
    {
        return x;
    }
    return f[x] = find(f[x]);
}

void debug(int a, int b)
{
    for (int i = 1; i <= b; i++)
    {
        cout << find(i) << " ";
    }
    cout << endl;
    return;
}

void solve()
{
    int a, b, p;
    cin >> a >> b >> p;
    pre(b);
    for (int i = 2; i <= b; ++i)
    {
        if (!vis[i])
        {
            if (i >= p)
            {
                for (int j = 2 * i; j <= b; j += i)
                {
                    vis[j] = 1;
                    int fa = find(j - i);
                    int fb = find(j);
                    if (fb != fa && j - i >= a)
                    {
                        f[fb] = fa;
                    }
                }
            }
            else
            {
                for (int j = 2 * i; j <= b; j += i)
                {
                    vis[j] = 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        if (find(i) == i)
        {
            ans++;
        }
    }
    // debug(a, b);
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