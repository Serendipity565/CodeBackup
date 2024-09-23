#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

void solve()
{

    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b(2 * n + 2);
    vector<ll> c(n + 1);
    ll cnt = 1;
    ll j = 1;
    cin >> a[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == a[i - 1])
        {
            cnt++;
        }
        else
        {
            b[j] = cnt;
            b[j + 1] = a[i - 1];
            c[(j + 1) / 2] = cnt + c[((j + 1) / 2 - 1)];
            cnt = 1;
            j += 2;
        }
    }
    b[j] = cnt;
    b[j + 1] = a[n];
    c[(j + 1) / 2] = cnt + c[((j + 1) / 2 - 1)];

    ll sum = 0;
    ll l = 1;
    ll p = 0, q = 0;
    ll ans;
    ll temp2 = 0;
    while (l <= j)
    {
        ll temp = b[l];
        ll r = l;
        ll rr = l;
        temp2 = 0;
        while (r + 2 <= j)
        {
            while (r + 2 <= j && b[r + 2 + 1] != b[l + 1])
            {
                temp2 += b[r + 2];
                r += 2;
            }
            if (r + 2 <= j && b[r + 2] >= temp2 && b[r + 2 + 1] == b[l + 1])
            {
                temp += b[r + 2] - temp2;
                temp2 = 0;
                r += 2;
                rr = r;
            }
            else
            {
                break;
            }
            if (b[r] > temp)
            {
                rr = r;
                break;
            }
        }
        if (temp > sum)
        {
            p = c[(l + 1) / 2 - 1] + 1;
            q = c[(rr + 1) / 2];
            sum = temp;
            ans = b[l + 1];
        }
        l = max(rr, l + 2);
    }
    cout << ans << " " << p << " " << q << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}