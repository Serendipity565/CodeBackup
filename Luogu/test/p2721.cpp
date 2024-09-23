#include<bits/stdc++.h>
using namespace std;
int tim,dd[10004]={0};//dd为购买时间
int mm[]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int b[10004]={0};
double c[10004]={0},dp[370]={0};
//b为投资时间，c为利率
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>tim>>b[i]>>c[i];
        dd[i]=tim%100+mm[tim/100];//转换时间
    }
    dp[1]=100000;
    for (int i=2;i<=366;i++)
    {
        dp[i]=dp[i-1];
        for (int j=1;j<=n;j++)
        {
            if (i==dd[j]+b[j])
            {
                dp[i]=max(dp[i],dp[dd[j]]*(1+(c[j]/100)/365*b[j]));
            }
        }
    }
    cout<<fixed<<setprecision(2)<<dp[365];
    return 0;
}