#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

map<string, int> sum;
map<string, bool> flag;
int ans1, ans2, n, m, l;
string s[100005], s1;

void debug()
{
    return;
}

ll myhash(string s, ll base, ll mod)
{
    ll hs = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        hs = hs * base + (s[i] - 'a' + 1);
        hs %= mod;
    }
    return hs;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1;
        flag[s1] = 1;
    }
    cin >> m;
    l = 1;
    for (int i = 1; i <= m; i++)
    {
        cin >> s[i];
        if (flag[s[i]])
        {
            sum[s[i]]++;
        }
        if (sum[s[i]] == 1)
        {
            ans1++;
            ans2 = i - l + 1;
        }
        while (l <= i)
        {
            if (!flag[s[l]])
            {
                l++;
                continue;
            }
            if (sum[s[l]] >= 2)
            {
                sum[s[l]]--, l++;
                continue;
            }
            break;
        }
        ans2 = min(ans2, i - l + 1);
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
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