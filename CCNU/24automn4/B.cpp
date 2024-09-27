#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll a[200005];
int b[200005];

void debug()
{
    return;
}

void solve()
{
    int n;
    int k;
    int cnt = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 1)
        {
            cnt++;
            b[cnt] = i;
        }
    }

    if (cnt >= k && (cnt - k) % 2 == 0)
    {
        cout << "YES" << endl;
        for (int i = 1; i <= k - 1; i++)
        {
            cout << b[i] << " ";
        }
        cout << n << endl;
    }
    else
    {
        cout << "NO" << endl;
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