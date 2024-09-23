#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
ll q = 998244353;
ll a[200005] = {0};

void debug()
{
    return;
}

void pre()
{
    a[0] = 1;
    for (int i = 1; i <= 2000; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            a[i] += a[j] * a[i - j - 1];
            a[i] %= q;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << a[n] << endl;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pre();
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}