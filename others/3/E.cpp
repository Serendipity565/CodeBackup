#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
int ni[30][30] = {0};
int di[30] = {0};
int temp[30] = {0};
int m[30] = {0};
int path[30] = {0};
int mymax = 0, mystep;

bool check(int now, int next)
{
    if (ni[now][next] == 1 && !m[next])
    {
        return 1;
    }
    return 0;
}

void dfs(int x, int sum, int step)
{
    if (sum > mymax)
    {
        mymax = sum;
        mystep = step;
        for (int i = 1; i <= step; i++)
        {
            path[i] = temp[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (check(x, i))
        {
            m[i] = 1;
            temp[step + 1] = i;
            dfs(i, sum + di[i], step + 1);
            m[i] = 0;
        }
    }
    return;
}

void debug()
{
    return;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> di[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> ni[i][j];
        }
    }
    for (int i = 0; i <= 25; i++)
    {
        ni[0][i] = 1;
    }
    dfs(0, 0, 0);
    for (int i = 1; i <= mystep; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    cout << mymax;
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