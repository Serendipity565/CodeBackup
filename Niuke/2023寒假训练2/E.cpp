#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        int n,m;
        scanf(" %d %d",&n,&m);
        int a[105]={0};
        for (int i=1;i<=n;i++)
        {
            scanf(" %d",&a[i]);
        }
        int x,y;
        for (int j=1;j<=m;j++)
        {
            scanf(" %d %d",&x,&y);
            if (x==1 || y==1)
            {
                a[1]+=3;
            }
        }
        int sum=1;
        for (int i=2;i<=n;i++)
        {
            if(a[i]>a[1])
            {
                sum++;
            }
        }
        printf("%d\n",sum);
        t--;
    }
    return 0;
}