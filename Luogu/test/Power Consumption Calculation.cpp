#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, p1, p2, p3, t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    ll l, r;
    ll temp = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        if (i == 1)
        {
            temp = l;
        }
        ans += min(l - temp, t1) * p1;
        if (l - temp > t1)
        {
            ans += (min(l - temp, t2 + t1) - t1) * p2;
        }
        if (l - temp > t1 + t2)
        {
            ans += (l - temp - t1 - t2) * p3;
        }
        ans += (r - l) * p1;
        temp = r;
    }
    cout << ans;
    return 0;
}
