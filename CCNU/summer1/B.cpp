#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
int a[1000006] = {0};
int b[1000006] = {0};

int er(int num)
{
    int l = 0;
    int r = 100;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (mid * 6 + num * 4 >= 600)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return r;
}

void solve()
{
    int n;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < m)
        {
            b[i] = -1;
        }

        else
        {
            b[i] = er(a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}