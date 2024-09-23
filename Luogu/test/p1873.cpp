#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tree[1000006]={0};
ll puanduan(int mid,int n)
{
    ll sum=0;
    for (int i=1;i<=n;i++)
    {
        if (tree[i]>mid)
        {
            sum+=tree[i]-mid;
        }
    }
    return sum;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tree[i]);
    }
    int l=1,r=1e9;
    int res;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (puanduan(mid,n)>=m)
        {
            res=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    printf("%d",res);
    return 0;
}