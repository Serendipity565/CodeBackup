#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
ll a[105] = {0};

void debug()
{

    return;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    ll mymax = 100000000;
    for (int i = 1; i <= n; i++)
    {
        ll temp = llabs((a[n] - a[i]) - (a[i] - a[0]));
        mymax = min(mymax, temp);
    }
    cout << mymax << endl;
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