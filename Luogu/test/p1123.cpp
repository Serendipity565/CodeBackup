#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10][10] = {0};
int b[10][10] = {0}; // 用于标记是否可以取
int mymax = 0;
bool check(int x, int y)
{
    if (b[x][y + 1] == 0 && b[x][y - 1] == 0 &&
        b[x - 1][y - 1] == 0 && b[x - 1][y] == 0 && b[x - 1][y + 1] == 0 &&
        b[x + 1][y - 1] == 0 && b[x + 1][y] == 0 && b[x + 1][y + 1] == 0)
        return 1;
    return 0;
}
void dfs(int x, int y, int res)
{
    mymax = max(res, mymax);
    int xi = x;
    int yi = y + 1;
    if (yi > m)
    {
        yi = 1;
        xi++;
        if (xi > n)
            return;
    }
    if (check(xi, yi))
    {
        b[xi][yi] = 1;
        dfs(xi, yi, res + a[xi][yi]);
        b[xi][yi] = 0;
    }
    dfs(xi, yi, res); //不取当前点的情况
}
int main()
{
    int t;
    scanf(" %d", &t);
    while (t > 0)
    {
        t--;
        scanf(" %d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf(" %d", &a[i][j]);
            }
        }
        dfs(1,0,0);
        printf("%d\n",mymax);
        mymax=0;
    }
    return 0;
}