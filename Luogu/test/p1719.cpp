#include<bits/stdc++.h>
using namespace std;
long long a[125][125]={0};
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            scanf("%lld",&a[i][j]);
            //处理数据
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    //开始计算最大加权面积
    long long mymin=0;
    for (int x=1;x<=n;x++)
    {
        for (int y=1;y<=n;y++)//遍历边长
        {
            for (int i=x;i<=n;i++)//遍历坐标
            {
                for (int j=y;j<=n;j++)
                {
                    if (a[i][j]-a[i-x][j]-a[i][j-y]+a[i-x][j-y]>mymin)
                    mymin=a[i][j]-a[i-x][j]-a[i][j-y]+a[i-x][j-y];
                }
            }
        }
    }
    printf("%lld",mymin);
    return 0;
}