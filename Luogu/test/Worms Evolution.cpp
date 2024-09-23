#include <bits/stdc++.h>
using namespace std;
int a[105] = {0};
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (a[i] + a[j] == a[k] && i != j && j != k && i != k)
                {
                    cout << k << " " << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}