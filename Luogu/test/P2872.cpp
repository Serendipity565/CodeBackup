#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int a[1003] = {0};
vector<pair<int, int>> ve(1003);
struct P3366
{
    int x, y;
    double z;
} b[2000006];

bool cmp(P3366 a1, P3366 a2)
{
    return a1.z < a2.z;
}

void debug()
{

    return;
}

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

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y, z;
    double cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        cin >> x >> y;
        ve[i] = {x, y};
    }
    int l, r;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        double lx = ve[l].first;
        double ly = ve[l].second;
        double rx = ve[r].first;
        double ry = ve[r].second;
        b[i].x = l;
        b[i].y = r;
        b[i].z = sqrt((lx - rx) * (lx - rx) + (ly - ry) * (ly - ry));
    }
    int k = m + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double lx = ve[i].first;
            double ly = ve[i].second;
            double rx = ve[j].first;
            double ry = ve[j].second;
            b[k].x = i;
            b[k].y = j;
            b[k].z = sqrt((lx - rx) * (lx - rx) + (ly - ry) * (ly - ry));
            k++;
        }
    }
    sort(b + m + 1, b + k, cmp);
    for (int i = 1; i <= m; i++)
    {
        int fx = find(b[i].x);
        int fy = find(b[i].y);
        if (fx != fy)
        {
            a[fx] = fy;
        }
    }
    for (int i = m + 1; i < k; i++)
    {
        int fx = find(b[i].x);
        int fy = find(b[i].y);
        if (fx != fy)
        {
            a[fx] = fy;
            cnt += b[i].z;
        }
    }
    cout << fixed << setprecision(2) << cnt << endl;
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