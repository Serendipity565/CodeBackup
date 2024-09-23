#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> p(n + 2, 0);
    for (int i = 2; i <= n; i++)
        cin >> p[i];
    vector<ll> a(n + 1, 0);
    a[1] = 501;
    for (int i = 2; i <= n; i++)
    {
        a[i] = p[i];
        while (a[i] <= p[i + 1])
            a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << '\n';
}

int main()
{
    freopen("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}