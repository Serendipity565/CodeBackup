#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[100005][3] = {0};
ll b[100005][3] = {0};

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    b[1][0] = a[1][0];
    b[1][1] = a[1][1];
    b[1][2] = a[1][2];
    for (int i = 2; i <= n; i++)
    {
        b[i][0] = max(b[i - 1][1], b[i - 1][2]) + a[i][0];
        b[i][1] = max(b[i - 1][0], b[i - 1][2]) + a[i][1];
        b[i][2] = max(b[i - 1][0], b[i - 1][1]) + a[i][2];
    }
    cout << max(max(b[n][0], b[n][1]), b[n][2]) << endl;
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