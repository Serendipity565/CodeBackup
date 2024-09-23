#include<bits/stdc++.h>
using namespace std;
int m[100005]={0};
int dp[100005]={0};
int myfind(int i,int l,int r)
{
    int li=l,ri=r;
    int res=r+1;
    while (li<=ri)
    {
        int mid=(li+ri)/2;
        if (dp[mid]>=i)
        {
            li=mid+1;
        }
        else
        {
            res=mid;
            ri=mid-1;
        }
    }
    return res;
}
int fuck(int i,int l,int r)
{
    int li=l,ri=r;
    int res;
    while (li<=ri)
    {
        int mid=(li+ri)/2;
        if (dp[mid]>=i)
        {
            res=mid;
            li=mid+1;
        }
        else
        {
            ri=mid-1;
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a;
    int n=0;
    while (cin>>a)
    {
        n++;
        m[n]=a;
    }
    int l=1,r=1;
    dp[1]=m[1];
    for (int i=2;i<=n;i++)//求最长降序序列
    {
        if (m[i]<=dp[r])
        {
            r++;
            dp[r]=m[i];
        }
        else
        {
            dp[myfind(m[i],l,r)]=m[i];
        }
    }
    printf("%d\n",r);
    //求需要几个炮
    int t=0;
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++)
    {
        if (m[i]>dp[1])
        {
            t++;
            dp[t]=m[i];
            for (int j=t;j>1;j--)//保持降序
            {
                swap(dp[j-1],dp[j]);
            }
        }
        else
        {
            dp[fuck(m[i],1,t)]=m[i];
        }
        
    }
    printf("%d",t);
    return 0;
}