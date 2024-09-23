#include<bits/stdc++.h>
using namespace std;
int n;
int ni[30][30]={0};//表示不同点之间的连接情况
int di[30]={0};//di表示地雷个数
int temp[30]={0};//用于记录路线
int m[30]={0};//用于标记是否走过
int path[30]={0};//记录最终路径结果
int mymax=0,mystep;
bool check(int now,int next)
{
    if (ni[now][next]==1 && !m[next])
    {
        return 1;
    }
    return 0;
}
void dfs(int x,int sum,int step)
{
    if (sum>mymax)
    {
        mymax=sum;
        mystep=step;
        for (int i=1;i<=step;i++)
        {
            path[i]=temp[i];
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (check(x,i))
        {
            m[i]=1;
            temp[step+1]=i;
            dfs(i,sum+di[i],step+1);
            m[i]=0;
        }
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    //输入数据
    for (int i=1;i<=n;i++)
    {
        cin>>di[i];
    }
    for (int i=1;i<n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            cin>>ni[i][j];
        }
    }
    //处理数据
    for (int i=0;i<=25;i++)
    {
        ni[0][i]=1;
    }
    dfs(0,0,0);
    for (int i=1;i<=mystep;i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
    cout<<mymax;
    return 0;
}