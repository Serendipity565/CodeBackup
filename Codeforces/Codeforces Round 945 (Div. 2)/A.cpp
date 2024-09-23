#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll sum = a + b + c;
    if (sum % 2 == 1)
    {
        cout << "-1" << "\n";
    }
    else
    {
        ll x = sum - max(max(a, b), c);
        sum = sum / 2;
        cout << min(x, sum) << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}