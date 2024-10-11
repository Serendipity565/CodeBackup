#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

struct B
{
    string s;
    int t;
} a[100005];

bool cmp(B a1, B a2)
{
    return a1.t > a2.t;
}

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
        cin >> a[i].s >> a[i].t;
    }
    sort(a + 1, a + 1 + n, cmp);
    cout << a[2].s << endl;
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