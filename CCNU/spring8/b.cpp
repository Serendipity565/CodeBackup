#include <bits/stdc++.h>
using namespace std;
int a[1005] = {0};
int b[1005] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int mymax = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int temp = 0;
            for (int k = 1; k <= n; k++)
            {
                if (k < i || k > j)
                {
                    if (a[k] == 1)
                    {
                        temp++;
                    }
                }
                else
                {
                    if (a[k] == 0)
                    {
                        temp++;
                    }
                }
            }
            mymax = max(mymax, temp);
        }
    }
    cout << mymax;
    return 0;
}