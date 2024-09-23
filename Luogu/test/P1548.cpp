#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int sum1 = 0;
    for (int i = 1; i <= min(n, m); i++)
    {
        sum1 += (n + 1 - i) * (m + 1 - i);
    }
    int sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i != j)
            {
                sum2 += (n + 1 - i) * (m + 1 - j);
            }
        }
    }
    cout << sum1 << " " << sum2;
    return 0;
}