#include<bits/stdc++.h>
using namespace std;
int xi,yi,n,m;
long long a[30][30]={0};
bool check(int x,int y)
{
    if (x>=1 && x<=n && y>=1 && y<=m)
    {
        if ((x==xi+2 || x==xi-2) && (y==yi-1 || y==yi+1))
        {
            return 0;
        }
        else if ((x==xi+1 || x==xi-1) && (y==yi-2 || y==yi+2))
        {
            return 0;
        }
        else if (x==xi && y==yi)
        {
            return 0;
        }
        return 1;
    }
    return 0;
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&xi,&yi);
    n++;m++;xi++;yi++;
    a[1][1]=1;
    for (int i=2;i<=n+m;i++)
    {
        for (int j=1;j<i;j++)
        {
            if (check(i-j,j))
            {
                a[i-j][j]+=a[i-j-1][j];
                a[i-j][j]+=a[i-j][j-1];
            }
        }
    }
    printf("%lld",a[n][m]);
    return 0;
}