#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n, k;
double x[1003] = {0};
double y[1003] = {0};
int a[1003] = {0};
int cnt = 0;

struct P4047
{
    int x, y;
    double z;
} d[1000006];

double distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool cmp(P4047 a1, P4047 a2)
{
    return a1.z < a2.z;
}

void debug()
{
    for (int i = 1; i <= cnt; i++)
    {
        cout << d[i].x << " " << d[i].y << " " << d[i].z << endl;
    }
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
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        a[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cnt++;
            d[cnt].x = i;
            d[cnt].y = j;
            d[cnt].z = distance(x[i], y[i], x[j], y[j]);
        }
    }
    sort(d + 1, d + 1 + cnt, cmp);

    int q = 0;
    int flag = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (q == n - k)
        {
            flag = 1;
        }
        int fx = find(d[i].x);
        int fy = find(d[i].y);
        if (fx != fy)
        {
            q++;
            a[fx] = fy;
            if (flag) // 写在里面，因为要不同的部落距离；
            {
                cout << fixed << setprecision(2) << d[i].z << endl;
                return;
            }
        }
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