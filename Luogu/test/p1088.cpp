#include <bits/stdc++.h>
using namespace std;
int a[10005] = {0};
int b[10005] = {0}; // 用于判断当前数字是否被使用过
int c[10005] = {0}; // 用于储存火星人的手指序号
int m;
bool flag = false;
void dfs(int n, int k) // k表示层数
{
    if (m < 0)
        return;
    if (k == n + 1)
    {
        flag = true;
        m--;
        if (m == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", a[i]);
            }
            m--;
        }
        return;
    }
    for (int i = 1; i <= n && m >= 0; i++)
    {
        if (b[i] == 0)
        {
            a[k] = i;
            if (a[k] == c[k] || flag == true) // 前半句条件用于剪枝，后半句用于m的运算
            {
                b[i] = 1;
                dfs(n, k + 1);
                b[i] = 0;
            }
        }
    }
}
int main()
{
    int n;
    scanf(" %d", &n);
    scanf(" %d", &m);
    for (int i = 1; i <= n; i++)
    {
        scanf(" %d", &c[i]);
    }
    m++;
    dfs(n, 1);
    return 0;
}