#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[200005] = {0};

void debug()
{

    return;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    ll j = 1;
    ll i = 1;
    ll mymax = 0;
    sort(a + 1, a + 1 + n);
    while (i <= n)
    {
        while (j <= n && sum + a[j] <= m)
        {
            if (llabs(a[j] - a[i]) <= 1)
            {
                sum += a[j];
            }
            else
            {
                break;
            }
            j++;
        }
        mymax = max(sum, mymax);

        sum -= a[i];
        i++;
    }
    cout << max(mymax, sum) << endl;
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