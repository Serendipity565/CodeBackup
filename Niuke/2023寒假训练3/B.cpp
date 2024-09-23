#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[310][310]={0};
bool check (int x,int y)
{
    if (a[x][y]==0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int k;
    int x[100000]={0};
    int y[100000]={0};
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=k;i++)
    {
        scanf(" %d %d",&x[i],&y[i]);
        a[x[i]][y[i]]=1;
    }
    int cnt=0;
    for (int i=1;i<=k;i++)
    {
        if (!check(x[i]-1,y[i]))
        {
            cnt++;
        }
        if (!check(x[i]+1,y[i]))
        {
            cnt++;
        }
        if (!check(x[i],y[i]-1))
        {
            cnt++;
        }
        if (!check(x[i],y[i]+1))
        {
            cnt++;
        }
    }
    printf("%d",4*k-cnt/2);

    return 0;
}