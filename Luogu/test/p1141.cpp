#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];  // 储存数据
int b[1005][1005] = {0};  // 标记是否走过
int c[1000005] = {0};     // 统计个数

bool legal_site(int x, int y, int n)
{
    if (x >= 1 && x <= n && y >= 1 && y <= n)
    {
        return 1;
    }
    return 0;
}

void dfs(int x, int y, int n, int j,int s)
{
    if (!legal_site(x,y,n) || a[x][y]-'0'!=s || b[x][y]!=0) return;
    b[x][y] = j;
    c[j]++;
    dfs(x - 1, y, n, j,!s);
    dfs(x + 1, y, n, j,!s);
    dfs(x, y - 1, n, j,!s);
    dfs(x, y + 1, n, j,!s);
}

int main()
{
    int n, m;
    char s;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf(" %c", &a[i][j]);
            
        }
    }

    int x, y;
    for (int j = 1; j <= m; j++)
    {
        scanf("%d %d", &x, &y);
        if (b[x][y] == 0)
        {
            dfs(x, y, n, j, a[x][y]-'0');
            printf("%d\n", c[j]);
        }
        else
        {
            printf("%d\n", c[b[x][y]]);
        }
    }
    return 0;
}
