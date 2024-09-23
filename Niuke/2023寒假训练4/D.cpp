#include<bits/stdc++.h>
using namespace std;
long long a[1005]={0};
long long check(int n)
{
    long long mymax=a[1];
    for (int i=2;i<=n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (a[i]-a[j]>mymax)
            {
                mymax=a[i]-a[j];
            }
        }
    }
    return mymax;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf(" %lld",&a[i]);
        a[i]=a[i]+a[i-1];
    }
    if (k==0)
    {
        printf("%lld\n",check(n));
    }
    else
    {
        long long sum=-1000000000;
        for (int i=1;i<n;i++)
        {
            long long res1=a[i+1]-a[i];
            long long res2=a[i]-a[i-1];
            a[i]=a[i]-res2+res1;
            if (check(n)>sum) sum=check(n);
            a[i]=a[i]+res2-res1;
        }
        printf("%lld\n",sum);
    }
    return 0;
}