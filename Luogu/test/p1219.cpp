#include<bits/stdc++.h>
using namespace std;
int a[15]={0};
int b[15][15]={0};//用于标记
int n;
int res=0;
bool check(int x,int y)
{
    for (int j=1;j<y;j++)
    {
        if (b[j][x]==1) return 0;
    }
    int i=1;
    while (y-i>=1 && x-i>=1)
    {
        if (b[y-i][x-i]==1)
        {
            return 0;
        }
        i++;
    }
    i=1;
    while (y-i>=1 && x+i<=n)
    {
        if (b[y-i][x+i]==1)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void dfs(int x,int y,int k)//k代表层数
{
    a[k]=x;
    if (k==n)
    {
        res++;
        if (res<=3)
        {
            for (int i=1;i<=n;i++)
            {
                printf("%d ",a[i]);
            }
            printf("\n");
        }
        return ;
    }
    for (int i=1;i<=n;i++)
    {
        if (check(i,y+1))
        {
            b[y+1][i]=1;
            dfs(i,y+1,k+1);
            b[y+1][i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(1,0,0);
    printf("%d",res);
    return 0;
}