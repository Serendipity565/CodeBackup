#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct person
{
    ll a;
    ll b;
    ll cnt;
    ll t;
    bool flag = 0;
} p[200005];

ll ans[200005];

bool cmp1(person p1, person p2)
{
    return p1.cnt > p2.cnt;
}

bool cmp2(person p1, person p2)
{
    return p1.t < p2.t;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n + m + 1; i++)
    {
        cin >> p[i].a;
    }
    for (int i = 1; i <= n + m + 1; i++)
    {
        cin >> p[i].b;
        p[i].cnt = p[i].a - p[i].b;
        p[i].t = i;
    }
    sort(p + 1, p + n + m + 2, cmp1);
    ll k = 0;
    ll sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n + m + 1; i++)
    {
        if (k < n)
        {
            k++;
            sum1 += p[i].a;
            p[i].flag = 1;
        }
        if (i > n + 1)
        {
            sum2 += p[i].b;
            p[i].flag = 0;
        }
    }
    ll u = p[n + 1].a, v = p[n + 1].b;
    sort(p + 1, p + n + m + 2, cmp2);
    for (int i = 1; i <= n + m + 1; i++)
    {
        ans[i] = sum1 + sum2;
        if (p[i].flag == 1)
        {
            ans[i] = ans[i] - p[i].a + u;
        }
        else if (p[i].flag == 0)
        {
            ans[i] = ans[i] - p[i].b + v;
        }
    }
    for (int i = 1; i <= n + m + 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
