#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
ll fp[10000002] = {0};
ll m;
ll f(ll i)
{
    if (fp[i])
    {
        return (fp[i]);
    }
    if (i == 1 || i == 2)
    {
        fp[i] = 1 % m;
        return fp[i];
    }
    else
    {
        fp[i] = (f(i - 1) + f(i - 2)) % m;
        return fp[i];
    }
}

void debug()
{
    return;
}

void solve()
{
    ll m;
    cin >> m;
    ll i = 1;
    while (f(i) != 0 || f(i + 1) != 1)
    {
        i++;
    }
    cout << i << endl;
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