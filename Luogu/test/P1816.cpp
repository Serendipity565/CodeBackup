#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[100005] = {0};
ll f[100005][30] = {0};

void pre()
{
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i <= 100004; i++)
    {
        a[i] = a[i / 2] + 1;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i][0];
    }
    pre();
    for (int j = 1; j <= 25; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    int x, y;
    int q;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        q = a[y - x + 1];
        cout << min(f[x][q], f[y - (1 << q) + 1][q]) << " ";
    }
    return 0;
}