#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{

    return;
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << endl;
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