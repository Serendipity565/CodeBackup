#include <bits/stdc++.h>
using namespace std;
int c[105] = {0};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    int x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        c[i] = c[i] * (n - i + 1);
    }
    int ans = 0;
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        x -= c[i];
        if (x >= 0)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    cout << ans;
    return 0;
}