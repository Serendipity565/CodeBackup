#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
ll p[100005] = {0};
struct d
{
    ll a;
    ll b;
    ll c;
} g[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    ll next;
    ll now = 1;
    cin >> now;
    for (int i = 1; i <= m - 1; i++)
    {
        cin >> next;
        p[min(now, next)]++;
        p[max(now, next)]--;
        now = next;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        p[i] += p[i - 1];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> g[i].a >> g[i].b >> g[i].c;
    }
    ll sum = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (p[i] * g[i].a <= (g[i].c + g[i].b * p[i]))
        {
            sum = sum + p[i] * g[i].a;
        }
        else
        {
            sum = sum + g[i].c + g[i].b * p[i];
        }
    }
    cout << sum;
    return 0;
}