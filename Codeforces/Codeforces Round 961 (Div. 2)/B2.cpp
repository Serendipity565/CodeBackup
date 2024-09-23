#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct B
{
    ll a;
    ll c;
} h[200005];

void debug()
{

    return;
}

bool cmp(B h1, B h2)
{
    return h1.a < h2.a;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll mymax = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i].c;
        ll q = min(m / h[i].a, h[i].c);
        mymax = max(mymax, q * h[i].a);
    }

    if (mymax == m)
    {
        cout << mymax << endl;
        return;
    }
    ll sum = 0;
    ll j = 1;
    ll i = 1;
    sort(h + 1, h + 1 + n, cmp);
    for (ll i = 1; i < n; i++)
    {
        ll j = i + 1;
        if (llabs(h[j].a - h[i].a) <= 1)
        {
            // cout << h[i].a << " " << h[j].a << endl;
            if (h[i].a * h[i].c + h[j].a * h[j].c <= m)
            {
                mymax = max(mymax, h[i].a * h[i].c + h[j].a * h[j].c);
            }
            else
            {
                ll k1 = min(m / h[i].a, h[i].c);
                ll pred = h[i].a * k1;
                ll next = m - pred;
                ll k2 = 0;
                if (next >= h[j].a)
                {
                    k2 = min(next / h[j].a, h[j].c);
                    pred += k2 * h[j].a;
                    next = m - pred;
                }
                // mymax = max(mymax, min(m / h[j].a, h[j].c - k2));
                pred += min(min(h[j].c - k2, k1), next);
                mymax = max(pred, mymax);
            }
        }
        if (mymax == m)
        {
            cout << mymax << endl;
            return;
        }
    }
    cout << mymax << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}