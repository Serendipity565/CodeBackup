#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

ll a[200005] = {0};

void debug()
{
    return;
}

ll find(int i, vector<int> ve[])
{
    ll temp = 1e12;
    if (ve[i].size() == 0)
    {
        return a[i];
    }
    for (auto j : ve[i])
    {
        temp = min(temp, find(j, ve));
    }
    if (a[i] > temp)
    {
        return temp;
    }
    else
    {
        return (temp + a[i]) / 2;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> ve[n + 2];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll temp;
    for (int i = 2; i <= n; i++)
    {
        cin >> temp;
        ve[temp].push_back(i);
    }
    ll mymin = 1e12;
    for (auto i : ve[1])
    {
        mymin = min(mymin, find(i, ve));
    }
    cout << a[1] + mymin << endl;
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
