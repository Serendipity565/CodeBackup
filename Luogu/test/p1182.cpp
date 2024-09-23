#include<bits/stdc++.h>
using namespace std;
int a[100005]={0};
int panduan(int mid,int n)
{
    int next=1;
    int ans=1;
    int sum=0;
    while (next<=n)
    {
        if (sum+a[next]>mid)
        {
            ans++;
            sum=0;
        }
        sum+=a[next];
        next++;
    }
    return ans;
}
int main()
{
    int n,m;
    int mymax=0;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mymax=max(mymax,a[i]);
    }
    int l=mymax,r=1e9;
    int res;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (panduan(mid,n)<=m)
        {
            res=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    printf("%d",res);
    return 0;
}