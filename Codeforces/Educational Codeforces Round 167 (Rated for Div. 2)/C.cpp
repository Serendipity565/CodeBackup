#include <bits/stdc++.h>
using namespace std;
int a[200005] = {0};
int b[200005] = {0};

void solve()
{
    int n;
    cin >> n;

    int sa = 0, sb = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
        {
            if (a[i] > b[i])
            {
                sa += a[i];
            }
            else
            {
                sb += b[i];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
        {
            if (sa > sb)
            {
                if (a[i] > 0)
                {
                    sb++;
                }
                else if (a[i] < 0)
                {
                    sa--;
                }
            }
            else
            {
                if (a[i] > 0)
                {
                    sa++;
                }
                else if (a[i] < 0)
                {
                    sb--;
                }
            }
        }
    }
    cout << min(sa, sb) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}