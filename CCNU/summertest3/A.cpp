#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

char c[105][105];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '.')
            {
                if ((i + j) % 2 == 0)
                {
                    c[i][j] = 'B';
                }
                else
                {
                    c[i][j] = 'W';
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << c[i][j];
        }
        cout << endl;
    }
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