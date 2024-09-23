#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int a[300005] = {0};
void debug(int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            a[i] = 1;
        }
        a[i] += a[i - 1];
    }
    int l, r;
    // debug(n);
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;
        cout << max(0, a[r - 1] - a[l - 1]) << endl;
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