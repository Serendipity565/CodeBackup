#include<bits/stdc++.h>
using namespace std;
int a[200005]={0};
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int ans1=0,ans2=0;
        int sum=0;
        for (int j=n;j>=1;j--)
        {
            if (a[j]==1)
            {
                ans1++;
            }
            else
            {
                ans2++;
            }
            if (ans1>0 && ans2>0 )
            {
                sum++;
                ans1=0;
                ans2=0;
            }
        }
        if (ans1 ||ans2)
        {
            sum+=max(ans1,ans2);
        }
        printf("%d\n",sum);
        t--;
    }
    return 0;
}