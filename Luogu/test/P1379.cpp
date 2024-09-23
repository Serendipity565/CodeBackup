#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n, g = 123804765;
int a[4][4], fx, fy, nx, ny;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<int> q;
map<int, int> v;
map<int, int> ans;
void solve()
{
    cin >> n;
    if (n == g)
    {
        cout << 0 << endl;
        return;
    }
    q.push(n);
    q.push(g);
    ans[n] = 0;
    ans[g] = 1;
    v[g] = 2;
    v[n] = 1;
    while (!q.empty())
    {
        ll now, cur = q.front();
        q.pop();
        now = cur;
        for (int i = 3; i >= 1; i--)
        {
            for (int j = 3; j >= 1; j--)
            {
                a[i][j] = now % 10, now /= 10;
                if (a[i][j] == 0)
                {
                    fx = i, fy = j;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            nx = fx + dx[i];
            ny = fy + dy[i];
            if (nx < 1 || nx > 3 || ny < 1 || ny > 3)
            {
                continue;
            }
            swap(a[fx][fy], a[nx][ny]);
            now = 0;
            for (int p = 1; p <= 3; p++)
            {
                for (int j = 1; j <= 3; j++)
                {
                    now = now * 10 + a[p][j];
                }
            }
            if (v[now] == v[cur])
            {
                swap(a[fx][fy], a[nx][ny]);
                continue;
            }
            if (v[now] + v[cur] == 3)
            {
                cout << ans[cur] + ans[now] << endl;
                exit(0);
            }
            ans[now] = ans[cur] + 1;
            v[now] = v[cur];
            q.push(now);
            swap(a[fx][fy], a[nx][ny]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}