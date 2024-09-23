#include<bits/stdc++.h>
using namespace std;
long long ti[1000006]={0};
int main()
{
    int n,q;
    long long tc;
    scanf("%d %d %lld",&n,&q,&tc);
    for(int i=1;i<=n;i++)
    {
        scanf(" %d",&ti[i]);
    }
    sort(ti+1,ti+1+n);
    for (int i=2;i<=n;i++)
    {
        ti[i]+=ti[i-1];
    }
    long long m;
    while (q>0)
    {
        scanf("%lld",&m);
        long long p=m/tc;
        if (p>n) p=n;
        printf("%lld\n",ti[n-p]+tc);
        q--;
    }
    return 0;
}