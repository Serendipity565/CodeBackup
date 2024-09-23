#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    int temp;
    int a[105] = {0};
    int p[105] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> temp;
        p[temp] = 1;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            if (a[j] > a[j + 1] && p[j] != 0)
            {
                int k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }

    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}