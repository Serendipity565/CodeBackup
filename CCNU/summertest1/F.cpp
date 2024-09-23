#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll a[200005] = {0};
ll k[200005] = {0};
int find(ll k, ll n)
{
    ll l = 1;
    ll r = n;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (a[mid] == k)
        {
            return mid;
        }
        else if (a[mid] > k)
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
    ll n;
    ll q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (ll i = 1; i <= q; i++)
    {
        cin >> k[i];
    }
    ll j = 1;
    ll cnt = 0;
    for (ll i = 1; i <= q; i++)
    {
        cnt += k[i];
        if (cnt >= a[n])
        {
            cout << n << endl;
            cnt = 0;
        }
        else
        {
            j = find(cnt, n);
            if (a[j] == cnt)
            {
                cout << n - j << endl;
            }
            else
            {
                cout << n - j + 1 << endl;
            }
        }
    }
    return 0;
}