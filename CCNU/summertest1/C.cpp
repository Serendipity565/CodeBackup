#include <bits/stdc++.h>
using namespace std;
int n;
int a[110] = {0};
int dp1[110] = {0};
int dp2[110] = {0};
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf(" %d", &a[i]);
    }
    int mymax = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && dp1[i] < dp1[j])
            {
                dp1[i] = dp1[j];
            }
        }
        dp1[i]++;
    }
    mymax = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j > i; j--)
        {
            if (a[i] > a[j] && dp2[i] < dp2[j])
            {
                dp2[i] = dp2[j];
            }
        }
        dp2[i]++;
    }
    mymax = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp1[i] + dp2[i] > mymax)
            mymax = dp1[i] + dp2[i];
    }
    printf("%d", n - (mymax - 1));
    return 0;
}