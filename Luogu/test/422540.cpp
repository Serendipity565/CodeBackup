#include<bits/stdc++.h>
using namespace std;
int t;
int a[200005]={0};
long long check(int k,int n)
{
    int p=1;
    for (int i=k;i<=n;i++)
    {
        if (a[i]>=p)
        {
            p++;
        }
        else
        {
            return p-1;
        }
    }
    return p-1;
}
int main()
{
    scanf("%d",&t);
    while (t>0)
    {
        int n;
        scanf("%d",&n);
        long long cnt=0;
        long long sum=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int i=1;
        while (i<=n)
        {
            cnt=check(i,n);
            sum+=cnt;
            i+=1;
        }
        printf("%lld\n",sum);
        t--;
    }
    return 0;
}