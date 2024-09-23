#include<bits/stdc++.h>
using namespace std;
int a[1000006]={0};
long long sum[5]={0};
int main()
{
    int n;

    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]=(a[i]+a[i-1])%3;
        sum[a[i]]++;
    }
    long long ans=sum[0];
    for (int i=0;i<=2;i++)
    {
        if (sum[i]>0)
        {
            ans+=sum[i]*(sum[i]-1)/2;
        }
    }

    printf("%lld",ans);
    return 0;
}