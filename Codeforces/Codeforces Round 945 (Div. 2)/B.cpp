#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll a[100005] = {0};
void solve()
{
    ll n;
    ll mymax = 1;
    ll j = 0;
    ll temp = 0;
    bool flag = true;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i > 1 && a[i] != a[i - 1])
        {
            flag = false;
        }
        if (a[i] > a[mymax])
        {
            mymax = i;
        }
    }
    if (flag == true || n == 1)
    {
        cout << "1" << "\n";
        return;
    }

    while (a[mymax] != 0)
    {
        temp = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (a[i] % 2 == 0 && i)
            {
                temp++;
            }
            else
            {
                if (temp != n)
                {
                    j = max(j, temp);
                }
                temp = 0;
            }
            if (i == n && temp != n)
            {
                j = max(j, temp);
            }
            a[i] /= 2;
        }
    }

    cout << j + 1 << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}