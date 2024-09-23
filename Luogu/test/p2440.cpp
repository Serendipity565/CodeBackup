#include<bits/stdc++.h>
using namespace std;
int tree[100005]={0};
long long panduan(int mid,int n)
{
    long long sum=0;
    for (int i=1;i<=n;i++)
    {
        sum+=tree[i]/mid;
    }
    return sum;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&tree[i]);
    }
    int l=1,r=1e8;
    int res=0;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (panduan(mid,n)>=k)
        {
            l=mid+1;
            res=mid;
        }
        else r=mid-1;
    }
    printf("%d",res);
    return 0;
}