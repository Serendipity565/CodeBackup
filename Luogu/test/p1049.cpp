#include <bits/stdc++.h>
using namespace std;
int v,n;
int ni[40]={0};
int dp[20004]={0};
int main()
{
    scanf("%d",&v);
    scanf(" %d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf(" %d",&ni[i]);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=v;j>=ni[i];j--)
        {
            dp[j]=max(dp[j],dp[j-ni[i]]+ni[i]);
        }
    }
    printf("%d",v-dp[v]);
    return 0;
} 