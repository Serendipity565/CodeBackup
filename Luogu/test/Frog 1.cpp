#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[100005] = {0};
ll b[100005] = {0};

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    b[2] = llabs(a[1] - a[2]);
    for (int i = 3; i <= n; i++)
    {
        b[i] = min(b[i - 1] + llabs(a[i] - a[i - 1]), b[i - 2] + llabs(a[i] - a[i - 2]));
    }
    cout << b[n] << endl;
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