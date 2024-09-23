#include<bits/stdc++.h>
using namespace std;
int dfs(int n,int k,int now)
{
    if (k==1)
    {
        return 1;
    }
    int sum=0;
    for (int i=now;i<=n/k;i++)
    {
        sum+=dfs(n-i,k-1,i);
    }
    return sum;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int res=dfs(n,k,1);
    printf("%d",res);
    return 0;
}