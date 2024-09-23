#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int a[1005][1005] = {0};
int n;

struct node
{
    int x;
    int y;
    int dep;
};

int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};

int x2, y2;

void bfs(int x1, int y1, int dep)
{
    queue<node> q;
    q.push({x1, y1, dep});
    a[x1][y1] = 1;
    node now;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (now.x + fx[i] <= n && now.x + fx[i] >= 1 && now.y + fy[i] >= 1 && now.y + fy[i] <= n && a[now.x + fx[i]][now.y + fy[i]] == 0)
            {
                if (now.x + fx[i] == x2 && now.y + fy[i] == y2)
                {
                    cout << now.dep << endl;
                    return;
                }
                a[now.x + fx[i]][now.y + fy[i]] = 1;
                q.push({now.x + fx[i], now.y + fy[i], now.dep + 1});
            }
        }
    }
}

void solve()
{

    cin >> n;
    char temp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> temp;
            a[i][j] = temp - '0';
        }
    }
    int x1, y1;
    cin >> x1 >> y1 >> x2 >> y2;
    bfs(x1, y1, 1);
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