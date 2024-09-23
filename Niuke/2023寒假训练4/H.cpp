#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t)
    {
        bool flag=true;
        int a[4][4]={0};
        int b[4][4]={0};//统计次数
        int n;
        scanf(" %d",&n);
        int x,y,z;
        for (int i=1;i<=n;i++)
        {
            scanf(" %d %d %d",&x,&y,&z); 
            b[x][y]++;
            if (b[x][y]>1 && z!=a[x][y])
            {
                flag=false;
            }
            if (x==y && z==1)
            {
                flag=false;
            }
            if (z==1 && a[y][x]==1)
            {
                flag=false;
            }
            if (a[3][1] && a[2][3])
            {
                if (a[1][2] || (!a[2][1] && b[2][1]))
                {
                    flag=false;
                }
            }
            if (a[1][2] && a[3][1])
            {
                if (a[2][3] || (!a[3][2] && b[3][2]))
                {
                    flag=false;
                }
            }
            if (a[2][1] && a[3][2])
            {
                if (a[1][3] || (!a[3][1] && b[3][1]))
                {
                    flag=false;
                }
            }
            if (a[1][3] && a[3][2])
            {
                if (a[2][1] || (!a[1][2] && b[1][2]))
                {
                    flag=false;
                }
            }
            if (a[2][1] && a[1][3])
            {
                if (a[3][2] || (!a[2][3] && b[2][3]))
                {
                    flag=false;
                }
            }
            a[x][y]=max(a[x][y],z);
        }
        if (a[1][2] && a[2][3])
        {
            if (a[3][1] || (!a[1][3] && b[1][3]))
            {
                flag=false;
            }
        }
        if (flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        t--;
    }
    return 0;
}