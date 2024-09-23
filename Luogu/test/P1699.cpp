#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
char n[15][15];
int k[15][15] = {0};
struct nod
{
    int x, y;
    int num;
};
void solve()
{
    int lx, ly;
    int rx, ry;
    int bx, by;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cin >> n[i][j];
            if (n[i][j] == 'B')
            {
                bx = i;
                by = j;
                k[i][j] = 1;
            }
            if (n[i][j] == 'R')
            {
                rx = i;
                ry = j;
                k[i][j] = 1;
            }
            if (n[i][j] == 'L')
            {
                lx = i;
                ly = j;
                k[i][j] = 1;
            }
        }
    }
    queue<nod> q;
    q.push({lx, ly, 0});
    nod temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        {
            if ((temp.x + 1 == bx && temp.y == by) || (temp.x - 1 == bx && temp.y == by) ||
                (temp.x == bx && temp.y + 1 == by) || (temp.x == bx && temp.y - 1 == by))
            {
                cout << temp.num << endl;
                return;
            }
            if (temp.x + 1 >= 1 && temp.x + 1 <= 10 && k[temp.x + 1][temp.y] == 0)
            {
                q.push({temp.x + 1, temp.y, temp.num + 1});
                k[temp.x + 1][temp.y] = 1;
            }
            if (temp.x - 1 >= 1 && temp.x - 1 <= 10 && k[temp.x - 1][temp.y] == 0)
            {
                q.push({temp.x - 1, temp.y, temp.num + 1});
                k[temp.x - 1][temp.y] = 1;
            }
            if (temp.y + 1 >= 1 && temp.y + 1 <= 10 && k[temp.x][temp.y + 1] == 0)
            {
                q.push({temp.x, temp.y + 1, temp.num + 1});
                k[temp.x][temp.y + 1] = 1;
            }
            if (temp.y - 1 >= 1 && temp.y - 1 <= 10 && k[temp.x][temp.y - 1] == 0)
            {
                q.push({temp.x, temp.y - 1, temp.num + 1});
                k[temp.x][temp.y - 1] = 1;
            }
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