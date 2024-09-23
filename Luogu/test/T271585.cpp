#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
ll a[1005][1005] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            a[i][j] = a[i][j] + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
        }
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */
    int x1, x2, y1, y2;
    for (int i = 1; i <= q; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}