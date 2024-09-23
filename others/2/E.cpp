#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{

    return;
}

void solve()
{
    ll n;
    cin >> n;
    ll a = n / 2;
    ll b = n / 3;
    ll c = n / 6;
    cout << n - (a + b - c) << endl;
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