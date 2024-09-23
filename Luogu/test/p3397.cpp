#include<bits/stdc++.h>
using namespace std;
int a[1005][1005]={0};
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int x1,y1,x2,y2;
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
        for (int i=y1;i<=y2;i++)
        {
            a[i][x1]++;a[i][x2+1]--;
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            a[i][j]+=a[i][j-1];
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;

}