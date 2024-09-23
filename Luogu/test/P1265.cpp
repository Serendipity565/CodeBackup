#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
double x[5010], y[5010], dis[5010];
int b[5010];
double ans = 0;

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void debug()
{

    return;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        dis[i] = 1e12 * 1.0;
    }
    dis[1] = 0.0;
    b[1] = 1;
    int curr;
    double minn;
    for (int i = 1; i <= n; i++)
    {
        curr = 1;
        minn = 1e9 * 1.0;
        for (int j = 1; j <= n; j++) // 找最短边
        {
            if (!b[j] && dis[j] < minn)
            {
                minn = dis[j], curr = j;
            }
        }
        b[curr] = true;
        ans += dis[curr];
        for (int j = 1; j <= n; j++) // 现用现算
        {
            dis[j] = min(dis[j], distance(x[curr], y[curr], x[j], y[j]));
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
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