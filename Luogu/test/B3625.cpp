#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
char n[108][105];
int k[105][105] = {0};
struct nod
{
    int x, y;
};
void solve()
{

    int p, m;
    cin >> p >> m;
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> n[i][j];
            if (n[i][j] == '#')
            {
                k[i][j] = 1;
            }
        }
    }
    queue<nod> q;
    q.push({1, 1});
    k[1][1] = 1;
    nod temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        {
            if ((temp.x + 1 == p && temp.y == m) || (temp.x - 1 == p && temp.y == m) ||
                (temp.x == p && temp.y + 1 == m) || (temp.x == p && temp.y - 1 == m))
            {
                cout << "Yes" << endl;
                return;
            }
            if (temp.x + 1 >= 1 && temp.x + 1 <= p && k[temp.x + 1][temp.y] == 0)
            {
                q.push({temp.x + 1, temp.y});
                k[temp.x + 1][temp.y] = 1;
            }
            if (temp.x - 1 >= 1 && temp.x - 1 <= p && k[temp.x - 1][temp.y] == 0)
            {
                q.push({temp.x - 1, temp.y});
                k[temp.x - 1][temp.y] = 1;
            }
            if (temp.y + 1 >= 1 && temp.y + 1 <= m && k[temp.x][temp.y + 1] == 0)
            {
                q.push({temp.x, temp.y + 1});
                k[temp.x][temp.y + 1] = 1;
            }
            if (temp.y - 1 >= 1 && temp.y - 1 <= m && k[temp.x][temp.y - 1] == 0)
            {
                q.push({temp.x, temp.y - 1});
                k[temp.x][temp.y - 1] = 1;
            }
        }
    }
    cout << "No" << endl;
    return;
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