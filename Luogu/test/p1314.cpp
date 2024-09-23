#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct kuang
{
    ll w;
    ll v;
}kuangshi[200005];
int li[200005],ri[200005];

ll panduan(int mid,int n,int m)
{
    ll wi[200005]={0};
    ll vi[200005]={0};
    ll sum=0;
    for (int i=1;i<=n;i++)
    {
        if (kuangshi[i].w>=mid)
        {
            wi[i]=wi[i-1]+1;
            vi[i]=vi[i-1]+kuangshi[i].v;
        }
        else
        {
            wi[i]=wi[i-1];
            vi[i]=vi[i-1];
        }
    }
    for (int j=1;j<=m;j++)
    {
        sum+=(wi[ri[j]]-wi[li[j]-1])*(vi[ri[j]]-vi[li[j]-1]);
    }
    return sum;
}

int main()
{
    int m,n;
    ll s;
    scanf("%d %d %lld",&n,&m,&s);
    //输入数据
    for (int i=1;i<=n;i++)
    {
        scanf("%lld %lld",&kuangshi[i].w,&kuangshi[i].v);
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&li[i],&ri[i]);
    }
    //二分查找
    int l=0,r=1000000;
    ll mymin=1e13;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll sum=panduan(mid,n,m);
        if (sum<s)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
        if (llabs(sum-s)<mymin)
        {
            mymin=llabs(sum-s);
            if (mymin==0) break;
        }
    }
    printf("%lld",mymin);
    return 0;
}