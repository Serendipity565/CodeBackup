#include <bits/stdc++.h>
using namespace std;
int a[105] = {0};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        if (a[i] <= 0)
        {
            sum -= a[i];
        }
    }
    cout << sum << endl;
    return 0;
}