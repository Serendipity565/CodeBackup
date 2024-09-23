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
    int a, b;
    cin >> a >> b;
    set<int> s;
    s.insert(2 * a - b);
    s.insert(2 * b - a);
    if ((a + b) % 2 == 0)
    {
        s.insert((a + b) / 2);
    }
    cout << s.size();
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