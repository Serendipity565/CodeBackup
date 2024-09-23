#include<bits/stdc++.h>
using namespace std;
int t,m;
int ti[105]={0};
int vi[105]={0};
int dp[10004]={0};
int main()
{
    scanf("%d %d",&t,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&ti[i],&vi[i]);
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=t;j>=ti[i];j--)
        {
            dp[j]=max(dp[j],dp[j-ti[i]]+vi[i]);
        }
    }
    printf("%d",dp[t]);
    return 0;
} 