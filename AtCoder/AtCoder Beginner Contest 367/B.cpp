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
    double x;
    cin >> x;
    int y = x;
    x -= y;
    cout << x + y << endl;
    // if (x < 0.1)
    // {
    //     cout << x + y << endl;
    // }
    // else
    // {
    //     cout << x << endl;
    // }
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