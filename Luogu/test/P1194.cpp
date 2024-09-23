#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
int a, b;
int f[555] = {0};
struct node
{
    int u, v, w;
} e[250000];

bool cmp(node a1, node a2)
{
    return a1.w < a2.w;
}

int find(int x)
{
    if (f[x] == x)
    {
        return x;
    }
    else
    {
        return f[x] = find(f[x]);
    }
}
void solve()
{
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            int temp;
            cin >> temp;
            if (i <= j && temp != 0)
            {
                ans++;
                e[ans].u = i;
                e[ans].v = j;
                e[ans].w = temp;
            }
        }
    }
    for (int i = 1; i <= b; i++)
    {
        ans++;
        e[ans].u = 0;
        e[ans].v = i;
        e[ans].w = a;
    }
    for (int i = 0; i <= b; i++)
    {
        f[i] = i;
    }
    sort(e + 1, e + ans + 1, cmp);
    ll cnt = 0;
    int tot = 1;
    int j = 1;
    while (j <= ans && tot <= b)
    {
        if (find(e[j].u) != find(e[j].v))
        {
            tot++;
            cnt += e[j].w;
            int fx = find(e[j].u);
            int fy = find(e[j].v);
            if (fx != fy)
            {
                f[fx] = fy;
            }
            // cout << e[j].u << "->" << e[j].v << " " << cnt << endl;
        }
        j++;
    }
    cout << cnt << endl;
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
