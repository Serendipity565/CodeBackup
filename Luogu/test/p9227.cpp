#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        t--;
        int n;
        long long k;
        unsigned int sum=0;
        unsigned int a[100008]={0};
        scanf(" %d %lld",&n,&k);
        if ((k%2!=0 && n%2==0) || n%2==1)
        {
            for (int i=1;i<=n;i++)
            {
                scanf("%u",&a[i]);
                sum=sum^a[i];
            }
            for (int i=1;i<n;i++)
            {
                printf("%u ",sum^a[i]);
            }
            printf("%u\n",sum^a[n]);
        }
        else
        {
            for (int i=1;i<=n;i++)
            {
                scanf("%u",&a[i]);
            }
            for (int i=1;i<n;i++)
            {
                printf("%u ",a[i]);
            }
            printf("%u\n",a[n]);
        }
    }
    return 0;
}