#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    char temp;
    char c;
    bool flag = true;
    map<char, int> mp;
    cin >> temp;
    mp[temp] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> c;
        if (mp[c] == 1 && temp != c)
        {
            flag = false;
        }
        mp[c] = 1;
        temp = c;
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}