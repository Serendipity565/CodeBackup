#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

ll n;
ll x;
ll h[100005] = {0};

bool check(ll y)
{
    ll sum = 0;
    for (ll i = 1; i <= y; i++)
    {
        sum += h[i];
    }
    if (sum >= x)
    {
        for (ll i = y + 1; i <= n - 1; i++)
        {
            sum = sum + h[i] - h[i - y];
            if (sum < x)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

ll erfen()
{
    ll l = 1;
    ll r = n - 1;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    ll ant = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        cin >> h[i];
        ant += h[i];
    }

    x = 2 * x;
    if (ant < x)
    {
        cout << n << endl;
        return 0;
    }
    cout << erfen() << endl;
    return 0;
}