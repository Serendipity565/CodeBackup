#include<bits/stdc++.h>
using namespace std;
typedef long long il;
il a[10000005]={0};
il panduan(il mid,il n)
{
    il ans=0;
    il now=1;
    il next=2;
    il i=0;
    while (next<=n)
    {
        if (a[next]-a[now]-i*mid>mid)
        {
            ans++;
            i++;
        }
        else
        {
            i=0;
            now++;
            next++;
        }
    }
    return ans;
}
int main()
{
    il l,n,k;
    scanf("%lld %lld %lld",&l,&n,&k);
    for (il i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    il i=1,j=l;
    il mid,res;
    while (i<=j)
    {
        mid=(i+j)/2;
        if (panduan(mid,n)<=k)
        {
            res=mid;
            j=mid-1;
        }
        else if(panduan(mid,n)>k) i=mid+1;
        //else j=mid-1;
    }
    printf("%lld",res);
    return 0;
}