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
    int n;
    cin >> n;
    ll a;
    ll fistbig = 0;
    ll secobig = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a > fistbig)
        {
            secobig = fistbig;
            fistbig = a;
        }
        else if (a > secobig)
        {
            secobig = a;
        }
    }
    cout << secobig + fistbig << endl;

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}