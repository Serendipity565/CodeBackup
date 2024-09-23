#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int a[35] = {0};

void debug()
{
    return;
}

ll getsize(ll n)
{
    ll len = 0;
    while (n)
    {
        n /= 10;
        len++;
    }
    return len;
}

void solve()
{
    int n;
    cin >> n;
    a[1] = 1;
    ll fm = 1;
    ll fz = 1;
    ll k;
    for (ll i = 2; i <= n; i++)
    {
        fz = fz * i + fm;
        fm = fm * i;
        k = __gcd(fz, fm);
        fz /= k;
        fm /= k;
    }
    if (n % fm == 0 || fm == 1)
    {
        cout << fz * (n / fm) << endl;
        return;
    }
    fz = fz * n;
    k = __gcd(fz, fm);
    fz /= k;
    fm /= k;
    if (fm == 1)
    {
        cout << fz << endl;
        return;
    }
    ll z = fz / fm;
    fz = fz - fz / fm * fm;
    for (int i = 1; i <= getsize(z); i++)
    {
        cout << " ";
    }
    cout << fz << endl;

    cout << z;
    for (int i = 1; i <= getsize(fm); i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 1; i <= getsize(z); i++)
    {
        cout << " ";
    }
    cout << fm << endl;
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