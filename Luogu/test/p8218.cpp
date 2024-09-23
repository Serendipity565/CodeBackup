#include<bits/stdc++.h>
using namespace std;
int temp[2000005];
long long temp1[2000005];
long long temp2[2000005];
int main()
{
    temp1[0]=0;
    temp2[0]=0;
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&temp[i]);
        temp1[i]=temp1[i-1]+temp[i];
        temp2[i]=temp2[i-1]^temp[i];

    }
    int a,l,r;
    for (int i=0;i<m;i++)
    {
        scanf("%d %d %d",&a,&l,&r);
        if (a==1) printf("%lld\n",temp1[r]-temp1[l-1]);
        else printf("%lld\n",temp2[r]^temp2[l-1]);
    }
    return 0;
}