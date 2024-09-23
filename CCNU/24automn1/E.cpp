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
    string p = "";
    map<char, int> mp;
    for (int i = 0; i < k; i++)
    {
        mp['a' + i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        if (s[i] - 'a' < k)
        {
            mp[s[i]]++;
            p = p + s[i];
        }
    }
    char temp;
    bool flaf = true;
    for (auto x : mp)
    {
        if (x.second < n)
        {
            flaf = false;
            temp = x.first;
        }
    }
    if (flaf)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        cout << "NO" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << temp;
        }
        cout << endl;
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