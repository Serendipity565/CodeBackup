#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

bool check(ll n)
{

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    ll n;
    ll k;
    cin >> n >> k;
    k++;
    n++;
    if (check(k) && (n < 2 * k))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
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