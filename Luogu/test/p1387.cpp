#include<bits/stdc++.h>
using namespace std;
int a[105][105]={0};
bool fin(int k,int n,int m)
{
    for (int i=k;i<=n;i++)
    {
        for (int j=k;j<=m;j++)
        {
            if (a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]==k*k)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    int k=min(n,m);
    while (k>0)
    {
        if (fin(k,n,m))
        {
            printf("%d",k);
            break;
        }
        else
        {
            k--;
        }
    }
    return 0;
}