#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
int r1, c1;
int r2, c2;
int d[55][55];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
queue<pair<int, int>> q2;
void debug()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout << d[i][j];
        }
        cout << endl;
    }
    return;
}

void find()
{
    int res = 1e9;
    for (int sx = 1; sx <= n; sx++)
    {
        for (int sy = 1; sy <= n; sy++)
        {
            if (d[sx][sy] == 5)
            {
                for (int tx = 1; tx <= n; tx++)
                {
                    for (int ty = 1; ty <= n; ty++)
                    {
                        if (d[tx][ty] == 6)
                        {
                            res = min(res, (sx - tx) * (sx - tx) + (sy - ty) * (sy - ty));
                        }
                    }
                }
            }
        }
    }
    cout << res << endl;
    return;
}

void solve()
{
    cin >> n;
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    char c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            d[i][j] = c - '0';
        }
    }
    q.push({r1, c1});
    d[r1][c1] = 5;
    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        if (now.first == r2 && now.second == c2)
        {
            cout << 0 << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && d[nx][ny] == 0)
            {
                d[nx][ny] = 5;
                q.push({nx, ny});
            }
        }
    }

    q2.push({r2, c2});
    d[r2][c2] = 6;
    while (!q2.empty())
    {
        pair<int, int> now = q2.front();
        q2.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && d[nx][ny] == 0)
            {
                d[nx][ny] = 6;
                q2.push({nx, ny});
            }
        }
    }
    // debug();
    find();
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