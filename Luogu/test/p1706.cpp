#include<bits/stdc++.h>
using namespace std;
int a[20]={0};
int b[20]={0};//用于判断当前数字是否被使用过
void dfs(int n,int k)//k表示层数
{
    if (k==n+1)
    {
        for (int i=1;i<=n;i++)
        {
            printf("%5d",a[i]);
        }
        printf("\n");
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (b[i]==0)
        {
            a[k]=i;
            b[i]=1;
            dfs(n,k+1);
            b[i]=0;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    dfs(n,1);
    return 0;
}