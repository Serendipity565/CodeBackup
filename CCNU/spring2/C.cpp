#include<bits/stdc++.h>
using namespace std;
long long a[100005]={0};
int main()
{
    long long x,n;
    scanf("%lld %lld",&x,&n);
    for (int i=1;i<=n;i++)
    {
        scanf(" %lld",&a[i]);
    }
    sort(a+1,a+1+n);
    long long ans=2;
    for (int i=1;i<=n;i++)
    {
        if (a[i]%2==0 && ans<=a[i])
        {
            ans=ans+2;
        }
    }
    if (ans>=x)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}