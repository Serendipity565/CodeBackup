#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        a[i] = -1;
    }
    int x, c;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> c;
        if (a[x] != -1)
            a[x] = min(a[x], c);
        else
            a[x] = c;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
            sum += a[i];
    }
    cout << min(sum, k) << endl;
    return 0;
}