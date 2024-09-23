#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int k[5] = {0};

void solve()
{
    int n;
    cin >> n;
    float x, y, z;
    cin >> x >> y >> z;
    float b, c;
    string a;
    map<string, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        if (a[3] == '1' && c >= 60.0)
        {
            x -= b;
            mp[a] = 0;
        }
        else if (a[3] == '1')
        {
            mp[a] = 1;
        }
        if (a[3] == '2' && c >= 60.0)
        {
            y -= b;
        }
        if (a[3] == '5' && c >= 60.0)
        {
            k[a[4] - '0'] = 1;
            z -= b;
        }
    }
    int sum = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (k[i] > 0)
        {
            sum++;
        }
    }
    for (auto x : mp)
    {
        if (x.second == 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (x <= 0.0 && y <= 0.0 && z <= 0.0 && sum >= 3 && k[3] > 0)
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
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}