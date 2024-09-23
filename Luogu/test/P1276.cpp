#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
int a[10005] = {0};
// 0成树，1幼苗，2空
void solve()
{
    int n, l;
    cin >> l >> n;
    int op, x, y;
    int ans = 0;
    int sum = 0;
    for (int j = 1; j <= n; j++)
    {
        cin >> op >> x >> y;
        if (op == 0)
        {
            for (int i = x; i <= y; i++)
            {
                if (a[i] == 1)
                {
                    ans++;
                    sum--;
                }
                a[i] = 2;
            }
        }
        else if (op == 1)
        {
            for (int i = x; i <= y; i++)
            {
                if (a[i] == 2)
                {
                    a[i] = 1;
                    sum++;
                }
            }
        }
    }

    cout << sum << endl
         << ans << endl;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}