#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int n;
int m;
int mymin = INT32_MAX;
int a[20] = {0};
int b[20] = {0};
void dfs(int now, int s, int v, int lr, int lh)
{
    if (now == m)
    {
        if (v == n)
        {
            mymin = min(mymin, s);
        }
        return;
    }
    if (v + b[m - now] > n) // 当前面积加上剩下层数最小面积大于n推出
    {
        return;
    }
    if (v + b[m - now] == n) // 当前面积加上剩下层数最小面积等于n
    {
        mymin = min(mymin, s + a[m - now]); // 加上唯一情况计较直接退出
        return;
    }
    if (s + 2 * (n - v) / (lr - 1) >= mymin) // 加上剩下层数最小面积大于最小退出
    {
        return;
    }
    if (s + a[m - now] > mymin) // 加上剩下层数最小面积大于最小退出
    {
        return;
    }
    for (int i = lr - 1; i >= m - now; i--)
    {
        for (int j = lh - 1; j >= m - now; j--)
        {
            dfs(now + 1, s + 2 * i * j, v + i * i * j, i, j);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> m;
    for (int i = 1; i <= 15; i++)
    {
        a[i] = a[i - 1] + 2 * i * i;
    }
    for (int i = 1; i <= 15; i++)
    {
        b[i] = b[i - 1] + i * i * i;
    }

    for (int i = (int)sqrt(n); i >= m; i--)
    {
        for (int j = (int)(n / i / i); j >= m; j--)
        {
            dfs(1, i * i + 2 * i * j, i * i * j, i, j);
        }
    }
    if (mymin == INT32_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mymin << endl;
    }
    return 0;
}