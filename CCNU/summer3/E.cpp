#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    map<string, ll> mp;
    string s;
    while (cin >> s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        mp[s]++;
    }
    ll mymax = 0;
    string ans;
    for (auto x : mp)
    {
        if (x.second > mymax)
        {
            mymax = x.second;
            ans = x.first;
        }
    }
    cout << ans << " " << mymax << endl;
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