#include <bits/stdc++.h>
using namespace std;
int a[200005] = {0};
int b[200005] = {0};

void solve()
{
    map<int, int> c; // 用于判断a是否在b中出现
    map<int, int> d; // 用于判断b中某个数的个数是否超过限制
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        c[b[i]]++;
    }

    int ans = 0;
    int cnt = 0;
    // 初始窗口
    for (int i = 0; i < m; i++)
    {
        if (c[a[i]] && d[a[i]] < c[a[i]])
        {
            ans++;
            d[a[i]]++;
        }
        else if (c[a[i]])
        {
            d[a[i]]++;
        }
    }
    if (ans >= k)
    {
        cnt++;
    }
    // 滑动窗口
    for (int i = m; i < n; i++)
    {
        // 前窗口部分
        if (c[a[i - m]] && d[a[i - m]] <= c[a[i - m]])
        {
            ans--;
            d[a[i - m]]--;
        }
        else if (c[a[i - m]])
        {
            d[a[i - m]]--;
        }
        // 后窗口部分
        if (c[a[i]] && d[a[i]] < c[a[i]])
        {
            ans++;
            d[a[i]]++;
        }
        else if (c[a[i]])
        {
            d[a[i]]++;
        }
        if (ans >= k)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}