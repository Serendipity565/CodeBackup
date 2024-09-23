#include<bits/stdc++.h>
using namespace std;
long long a[200005]={0};
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        int n;
        long long sum=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        for (int i=n;i>1;i--)
        {
            sum+=a[i]*4*(i-1);
        }
        printf("%lld\n",sum);
        t--;
    }
    return 0;
}