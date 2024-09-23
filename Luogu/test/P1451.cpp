#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int cnt = 0;
int a[105][105] = {0};
int n, m;

void dfs(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m)
    {
        return;
    }
    if (a[i][j] == 0)
    {
        return;
    }
    a[i][j] = 0;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    char temp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> temp;
            a[i][j] = temp - '0';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != 0)
            {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}