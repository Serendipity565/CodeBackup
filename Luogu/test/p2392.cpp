#include<bits/stdc++.h>
using namespace std;
int a[10][25]={0};
int b[10]={0};
int l;
int r;
int mymax;
void dfs(int k,int m)
{
    if (k==b[m]+1)
    {
        mymax=min(mymax,max(r,l));
        return ;
    }
    l+=a[m][k];
    dfs(k+1,m);
    l-=a[m][k];
    r+=a[m][k];
    dfs(k+1,m);
    r-=a[m][k];

}
int main()
{
    scanf("%d %d %d %d",&b[1],&b[2],&b[3],&b[4]);
    for (int i=1;i<=4;i++)
    {
        for (int j=1;j<=b[i];j++)
        {
            scanf(" %d",&a[i][j]);
        }
    }
    int res=0;
    for (int i=1;i<=4;i++)
    {
        l=0;r=0;mymax=1e5;
        dfs(1,i);
        //cout<<mymax<<endl;
        res+=mymax;
    }
    printf("%d",res);
    return 0;
}