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
    int a;
    char s;
    int li = 0;
    int ri = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> s;
        if (s == 'L' && li == 0)
        {
            li = a;
        }
        else if (s == 'R' && ri == 0)
        {
            ri = a;
        }
        else if (s == 'L')
        {
            ans += abs(li - a);
            li = a;
        }
        else if (s == 'R')
        {
            ans += abs(ri - a);
            ri = a;
        }
    }
    cout << ans << endl;
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