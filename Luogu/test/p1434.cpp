#include <bits/stdc++.h>
using namespace std;
int r, c;
struct p
{
    int x, y;
    int num;
} pi;
struct cmp
{
    bool operator()(p a, p b)
    {
        return a.num > b.num;
    }
};
bool check(int x, int y)
{
    if (x >= 1 && x <= c && y >= 1 && y <= r)
    {
        return 1;
    }
    return 0;
}
priority_queue<p, vector<p>, cmp> q;
int a[110][110] = {0};
int b[110][110] = {0};
int xi, yi, ni;
int mymin = 1e9;
int mymax = 0;
int main()
{
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            scanf(" %d", &a[i][j]);
            pi.y = i;
            pi.x = j;
            pi.num = a[i][j];
            q.push(pi);
        }
    }
    while (!q.empty())
    {
        xi = q.top().x;
        yi = q.top().y;
        ni = q.top().num;
        q.pop();
        if (check(xi - 1, yi) && a[yi][xi] > a[yi][xi - 1])
            b[yi][xi] = max(b[yi][xi], b[yi][xi - 1]);
        if (check(xi + 1, yi) && a[yi][xi] > a[yi][xi + 1])
            b[yi][xi] = max(b[yi][xi], b[yi][xi + 1]);
        if (check(xi, yi - 1) && a[yi][xi] > a[yi - 1][xi])
            b[yi][xi] = max(b[yi][xi], b[yi - 1][xi]);
        if (check(xi, yi + 1) && a[yi][xi] > a[yi + 1][xi])
            b[yi][xi] = max(b[yi][xi], b[yi + 1][xi]);
        b[yi][xi]++;
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (b[i][j] > mymax)
                mymax = b[i][j];
        }
    }
    printf("%d", mymax);
    return 0;
}