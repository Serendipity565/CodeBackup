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
    int k = n / 2;
    if (n % 2 == 0)
    {
        cout << (k + 1) * (k + 1) << endl;
    }
    else
    {
        cout << 2 * (k + 1) * (k + 2) << endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}