#include<bits/stdc++.h>
using namespace std;
int school[100005];
//二分查找
int myfind(int fenshu,int m)
{
    int l=1,r=m;
    int mymin=1e9;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (abs(school[mid]-fenshu)<mymin) mymin=abs(school[mid]-fenshu);
        if (school[mid]>fenshu)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
        if (mymin==0) return mymin;
    }
    return mymin;
}
//主函数
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&school[i]);
    }
    sort(school+1,school+m+1);
    int fenshu;
    long long sum=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&fenshu);
        sum+=myfind(fenshu,m);
    }
    printf("%lld",sum);
    return 0;
}