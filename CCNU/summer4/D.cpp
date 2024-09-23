#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

char c[100005];
int a[100005] = {0};
void debug()
{

    return;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    for (int i = 1; i + 2 <= n; i++)
    {
        if (c[i] == 'x' && c[i + 1] == 'j' && c[i + 2] == 'x')
        {
            a[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    int l, r;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        cout << max(a[r - 2] - a[l - 1], 0) << endl;
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