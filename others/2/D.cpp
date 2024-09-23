#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
map<char, int> mp;

void debug()
{

    return;
}

void pre()
{
    mp['a'] = 1;
    mp['b'] = 1;
    mp['c'] = 0;
    mp['d'] = 1;
    mp['e'] = 1;
    mp['f'] = 0;
    mp['g'] = 1;
    mp['h'] = 0;
    mp['i'] = 0;
    mp['j'] = 0;
    mp['k'] = 0;
    mp['l'] = 0;
    mp['m'] = 0;
    mp['n'] = 0;
    mp['o'] = 1;
    mp['p'] = 1;
    mp['q'] = 1;
    mp['r'] = 0;
    mp['s'] = 0;
    mp['t'] = 0;
    mp['u'] = 0;
    mp['v'] = 0;
    mp['w'] = 0;
    mp['x'] = 0;
    mp['y'] = 0;
    mp['z'] = 0;
    mp['A'] = 1;
    mp['B'] = 2;
    mp['C'] = 0;
    mp['D'] = 1;
    mp['E'] = 0;
    mp['F'] = 0;
    mp['G'] = 0;
    mp['H'] = 0;
    mp['I'] = 0;
    mp['J'] = 0;
    mp['K'] = 0;
    mp['L'] = 0;
    mp['M'] = 0;
    mp['N'] = 0;
    mp['O'] = 1;
    mp['P'] = 1;
    mp['Q'] = 1;
    mp['R'] = 1;
    mp['S'] = 0;
    mp['T'] = 0;
    mp['U'] = 0;
    mp['V'] = 0;
    mp['W'] = 0;
    mp['X'] = 0;
    mp['Y'] = 0;
    mp['Z'] = 0;
    mp['0'] = 1;
    mp['1'] = 0;
    mp['2'] = 0;
    mp['3'] = 0;
    mp['4'] = 1;
    mp['5'] = 0;
    mp['6'] = 1;
    mp['7'] = 0;
    mp['8'] = 2;
    mp['9'] = 1;
}

void solve()
{
    string s;
    cin >> s;
    ll ans = 0;
    pre();
    for (int i = 0; i < s.size(); i++)
    {
        ans += mp[s[i]];
    }
    cout << ans << endl;

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