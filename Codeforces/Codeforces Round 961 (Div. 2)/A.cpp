#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int a[105][105] = {0};

void debug()
{

    return;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int i = n;
    int ans = 0;
    if (k >= n)
    {
        k -= n;
        ans++;
    }
    i--;
    while (k > 0 && i > 0)
    {
        k -= i;
        ans++;
        if (k > 0)
        {
            k -= i;
            ans++;
        }
        i--;
    }
    cout << min(ans, 2 * n - 1) << endl;
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