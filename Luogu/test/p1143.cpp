#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[410][410]={0};
queue <vector<int> > q;
int step[16]={2,-1,2,1,1,-2,1,2,-2,-1,-2,1,-1,-2,-1,2};
bool check(int x,int y)
{
    if (x>=1 && x<=m && y>=1 && y<=n && a[y][x]==0) return 1;
    return 0;
}
void bfs(int x,int y)
{
    q.push({x,y,0});
    while (!q.empty())
    {
        x=q.front()[0];
        y=q.front()[1];
        k=q.front()[2];
        q.pop();
        for (int i=0;i<=14;i+=2)
        {
            if (check(x+step[i],y+step[i+1]))
            {
                q.push({x+step[i],y+step[i+1],k+1});
                a[y+step[i+1]][x+step[i]]=k+1;
            }
        }
    }
}
int main()
{
    int x,y;
    scanf("%d %d %d %d",&n,&m,&y,&x);
    bfs(x,y);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (i==y && j==x)
            {
                printf("%-5d",0);
            }
            else if (a[i][j]==0)
            {
                printf("%-5d",-1);
            }
            else
            {
                printf("%-5d",a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}