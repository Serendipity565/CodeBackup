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
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    if (s1.size() != s2.size())
    {
        cout << "No" << endl;
        return;
    }
    int diff = (s1[0] - s2[0] + 26) % 26;
    for (int i = 1; i < s1.size(); i++)
    {
        if ((s1[i] - s2[i] + 26) % 26 != diff)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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
