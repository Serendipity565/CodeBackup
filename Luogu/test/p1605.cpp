#include<bits/stdc++.h>
using namespace std;
int a[15][15]={0};
int b[15][15]={0};//标记是否走过
int res=0;
bool illegal_site(int x,int y,int n,int m)
{
    if (x>=1 && y>=1 && x<=n && y<=m)
    {
        return 0;
    }
    return 1;
}
void dfs(int x,int y,int fx,int fy,int n,int m)
{
    if (a[x][y]==1 || illegal_site(x,y,n,m) || b[x][y]==1) return ;
    if (x==fx && y==fy)
    {
        res++;
        return ;
    }
    b[x][y]=1;
    dfs(x-1,y,fx,fy,n,m);
    dfs(x+1,y,fx,fy,n,m);
    dfs(x,y-1,fx,fy,n,m);
    dfs(x,y+1,fx,fy,n,m);
    b[x][y]=0;
}
int main()
{
    int n,m,t;
    scanf(" %d %d %d",&n,&m,&t);
    int sx,sy,fx,fy;
    scanf(" %d %d %d %d",&sx,&sy,&fx,&fy);
    int x,y;
    for (int i=1;i<=t;i++)
    {
        scanf(" %d %d",&x,&y);
        a[x][y]=1;
    }
    dfs(sx,sy,fx,fy,n,m);
    printf("%d",res);
    return 0;
}