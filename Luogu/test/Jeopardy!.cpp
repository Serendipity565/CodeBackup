#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

bool cmp(ll a, ll b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    vector<ll> a;
    vector<ll> b;
    cin >> n >> m;
    ll sum1 = 0;
    ll sum2 = 0;
    ll temp;
    for (ll i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back(temp);
        sum1 += temp;
    }
    sum2 = sum1;
    for (ll i = 1; i <= m; i++)
    {
        cin >> temp;
        b.push_back(a[temp - 1]);
        sum2 -= a[temp - 1];
    }
    // cout << sum2 << endl;
    sort(b.begin(), b.end(), cmp);
    for (ll i = 0; i < m; i++)
    {
        if (sum2 + b[i] > sum2 * 2)
        {
            sum2 += b[i];
        }
        else
        {
            sum2 *= 2;
        }
    }
    cout << max(sum1, sum2);
    return 0;
}