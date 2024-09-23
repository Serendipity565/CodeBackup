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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return b.first > a.first && b.second > a.second;
}

void solve()
{
    int h, w;
    int n;
    cin >> h >> w >> n;
    vector<pair<int, int>> c;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        c.push_back({x, y});
    }
    sort(c.begin(), c.end(), cmp);
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