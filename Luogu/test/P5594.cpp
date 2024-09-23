#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
int a[1003][1003] = {0};
map<int, set<int>> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            mp[a[i][j]].insert(j);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cout << mp[i].size() << " ";
    }
    return 0;
}