#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[25][25]={0};
int b[25][25]={0};//用于标记
int res=0;
int mymax=0;
int xi=0,yi=0;
void  find()
{
    for (int i=1;i<=n;i++)//i stand for y
    {
        for (int j=1;j<=m;j++)//j stand for x
        {
            if (a[i][j]>mymax && b[i][j]==0)
            {
                mymax=a[i][j];
                xi=j;yi=i;
            }
        }
    }
}
void dfs(int k,int x,int y)
{
    if (k<y) return ;
    res+=a[y][x];
    xi=0;yi=0;
    mymax=0;
    find();
    b[yi][xi]=1;
    dfs(k-abs(x-xi)-abs(y-yi)-1,xi,yi);
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            scanf(" %d",&a[i][j]);
        }
    }
    find();
    b[yi][xi]=1;
    dfs(k-yi-1,xi,yi);
    printf("%d",res);
    return 0;
}