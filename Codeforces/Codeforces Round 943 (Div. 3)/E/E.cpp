#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    vector<int> mp(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n - 1; i += 2)
    {
        int x = i;
        if (x == 3)
            x = 2;
        if (x <= n)
        {
            printf("%d %d\n", x, 1);
        }
        else
        {
            auto x_ = x - n + 1;
            printf("%d %d\n", n, x_);
        }
    }
    printf("\n");
}

int main()
{
    // freopen("E.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}