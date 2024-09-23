#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

char s[1005][1005] = {0};
int q[1005][1005] = {0};
int n, m;

struct a
{
    int x;
    int y;
    int step;
};

void bfs()
{
    queue<a> que;
    que.push({1, 1, 1});
    q[1][1] = 1;
    while (!que.empty())
    {
        auto k = que.front();
        que.pop();
        if (k.x + 1 <= n && k.x + 1 >= 1 && q[k.x + 1][k.y] == 0)
        {
            if (k.x + 1 == n && k.y == m)
            {
                cout << k.step << endl;
                return;
            }
            que.push({k.x + 1, k.y, k.step + 1});
            q[k.x + 1][k.y] = 1;
        }
        if (k.y + 1 <= m && k.y + 1 >= 1 && q[k.x][k.y + 1] == 0)
        {
            if (k.x == n && k.y + 1 == m)
            {
                cout << k.step << endl;
                return;
            }
            que.push({k.x, k.y + 1, k.step + 1});
            q[k.x][k.y + 1] = 1;
        }
        if (k.x - 1 <= n && k.x - 1 >= 1 && q[k.x - 1][k.y] == 0)
        {
            if (k.x - 1 == n && k.y == m)
            {
                cout << k.step << endl;
                return;
            }
            que.push({k.x - 1, k.y, k.step + 1});
            q[k.x - 1][k.y] = 1;
        }
        if (k.y - 1 <= m && k.y - 1 >= 1 && q[k.x][k.y - 1] == 0)
        {
            if (k.x == n && k.y - 1 == m)
            {
                cout << k.step << endl;
                return;
            }
            que.push({k.x, k.y - 1, k.step + 1});
            q[k.x][k.y - 1] = 1;
        }
    }
    cout << -1 << endl;
    return;
}

void solve()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == '~')
            {
                q[i][j] = 1;
            }
        }
    }
    bfs();
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