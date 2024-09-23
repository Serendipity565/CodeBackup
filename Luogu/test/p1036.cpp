#include<bits/stdc++.h>
using namespace std;
int a[30]={0};
bool zhishu(int m)
{
    if (m<=2) return 1;
    for (int i=2;i*i<=m;i++)
    {
        if (m%i==0) return 0;
    }
    return 1;
}
int sum=0;
void dfs(int n,int k,int now,int *res)   //k表示当前层数
{
    if (k==0)
    {
        if (zhishu(sum))
        {
            *res+=1;
        }
        return ;
    }
    for (int i=now;i<=n;i++)
    {
        sum+=a[i];
        dfs(n,k-1,i+1,res);
        sum-=a[i];
    }
    return ;
}
int main()
{
    int n,k;
    int res=0;
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    dfs(n,k,1,&res);
    printf("%d",res);
    return 0;
}