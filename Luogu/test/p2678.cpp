#include <bits/stdc++.h>
using namespace std;
int a[50005]={0};
int panduan(int mid,int n)
{
    int i=0;//i为当前石头
    int k=1;//k为下一块石头
    int ans=0;
    while (k<=n+1)
    {
        if (a[k]-a[i]<mid)
        {
            ans++;
        }
        else
        {
            i=k;
        }
        k++;
    }
    return ans;
}
int main()
{
    int l,n,m;
    scanf("%d %d %d",&l,&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    a[n+1]=l;
    int i=1,j=l;
    int res;
    while (i<=j)
    {
        int mid=(i+j)/2;
        if (panduan(mid,n)<=m)
        {
            res=mid;
            i=mid+1;
        }
        else j=mid-1;
    }
    printf("%d",res);
    return 0;
}