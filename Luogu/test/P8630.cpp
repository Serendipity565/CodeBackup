#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

ll ans[200001] = {0};

void debug()
{
    return;
}

ll myhash(string s, ll base, ll mod)
{
    ll hs = 0;
    for (char c : s)
    {
        hs = hs * base + (c - 'a' + 1);
        hs %= mod;
    }
    return hs;
}

void solve()
{
    string s;
    int n;
    cin >> s;
    cin >> n;
    ll base = 100;
    ll mod = 1e9 + 9;
    int str_len = s.size();

    for (int i = 0; i + 7 < str_len; i++)
    {
        map<char, int> mp;
        for (int j = i; j < i + 8; j++)
        {
            mp[s[j]]++;
        }

        string s1 = "";
        for (auto x : mp)
        {
            s1 += string(x.second, x.first);
        }
        ans[i] = myhash(s1, base, mod);
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;

        map<char, int> mp;
        for (char c : s1)
        {
            mp[c]++;
        }

        string s2 = "";
        for (auto x : mp)
        {
            s2 += string(x.second, x.first);
        }

        ll k = myhash(s2, base, mod);
        for (int j = 0; j + 7 < str_len; j++)
        {
            if (k == ans[j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
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
