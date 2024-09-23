#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct D
{
    ll num;
    int id;
    bool u;
} a[2003];

bool cmp1(D a1, D a2)
{
    return a1.num > a2.num;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].num;
        a[i].id = i;
        a[i].u = true;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}