#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    ll cnt = 0;
    for (int i = 0; i + 2 < n; i++)
    {
        if (s1[i] == 'x' && s1[i + 1] == '.' && s1[i + 2] == 'x' && s2[i] == '.' && s2[i + 1] == '.' && s2[i + 2] == '.')
        {
            cnt++;
        }
        if (s2[i] == 'x' && s2[i + 1] == '.' && s2[i + 2] == 'x' && s1[i] == '.' && s1[i + 1] == '.' && s1[i + 2] == '.')
        {
            cnt++;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}