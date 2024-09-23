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
    int n, k;
    int m;
    string s;
    cin >> n >> k >> m;
    cin >> s;
    bool f[k];
    for (int i = 0; i < k; i++)
    {
        f[i] = false;
    }
    string p = "";
    string res = "";
    for (int i = 0; i < m; i++)
    {
        if (s[i] - 'a' < k)
        {
            p = p + s[i];
        }
    }
    int cnt = 0;
    for (auto x : p)
    {
        if (res.size() == n)
        {
            cout << "YES" << endl;
            return;
        }
        cnt += (!f[x - 'a']);
        f[x - 'a'] = true;
        if (cnt == k)
        {
            for (int i = 0; i < k; i++)
            {
                f[i] = false;
            }
            cnt = 0;
            res += x;
        }
    }
    // cout << res.size() << endl;
    if (res.size() == n)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    for (int i = 0; i < k; i++)
    {
        if (!f[i])
        {
            while (res.size() < n)
            {
                res += ('a' + i);
            }
            cout << res << endl;
            return;
        }
    }
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