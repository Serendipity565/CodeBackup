#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    int pos = 1, ans = -1;
    for (int i = 1; i <= n; i++)
    {
        while (pos <= m && s1[i] != s2[pos])
            pos += 1;
        if (pos > m)
        {
            ans = i - 1;
            break;
        }
        pos += 1;
    }
    if (ans == -1)
        ans = n;
    cout << ans << '\n';
}

int main()
{
    freopen("B.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}