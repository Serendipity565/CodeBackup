#include<bits/stdc++.h>
using namespace std;
long long a[100005]={0};
long long b[100005]={0};
long long ans=1e16;
long long n;
long long fin(long long p)
{
    if (p>b[n]) return -1;
    return *lower_bound (b+1,b+n+1,p);
}
int main()
{

    long long m;
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf(" %lld",&a[i]);
        a[i]=a[i]%m;
    }
    for (int i=1;i<=n;i++)
    {
        scanf(" %lld",&b[i]);
        b[i]=b[i]%m;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);

    for (int i=1;i<=n;i++)
    {
        ans=min((a[i]+b[1])%m,ans);
        long long temp=fin(m-a[i]);
        if (temp!=-1)
        {
            ans=min(ans,(a[i]+temp)%m);
        }
    }
    printf("%lld",ans);
    return 0;
}