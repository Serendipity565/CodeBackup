#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void debug()
{
    return;
}

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll num = -1;
    if (b % 3 + c < 3 && b % 3 != 0)
    {
        cout << num << endl;
    }
    else
    {
        num = a;
        num += ((b + c) / 3 + ((b + c) % 3 ? 1 : 0));
        cout << num << endl;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}