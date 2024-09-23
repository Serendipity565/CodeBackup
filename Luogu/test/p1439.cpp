#include<bits/stdc++.h>
using namespace std;
int n;
int p1[100005]={0};
int p2[100005]={0};
int ma[100005]={0};
int myfind(int i,int l,int r)
{
    int li=l,ri=r;
    int res=r+1;
    while (li<=ri)
    {
        int mid=(li+ri)/2;
        if (ma[mid]<i)
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
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf(" %d",&p1[i]);
        ma[p1[i]]=i;
    }
    for (int i=1;i<=n;i++)
    {
        scanf(" %d",&p2[i]);
        p2[i]=ma[p2[i]];
    }
    memset(ma,0,sizeof(ma));
    int r=1;
    ma[1]=p2[1];
    for (int i=2;i<=n;i++)
    {
        if (p2[i]>ma[r])
        {
            r++;
            ma[r]=p2[i];
        }
        else
        {
            ma[myfind(p2[i],1,r)]=p2[i];
        }
    }
    printf("%d",r);
    return 0;
}