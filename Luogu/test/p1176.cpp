#include<bits/stdc++.h>
using namespace std;
int a[1005][1005]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    int x,y;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if (x>0 && y>0)
        {
            a[x][y]=-1;
        }
    }
    a[1][1]=1;
    for (int i=3;i<=n+n;i++)
    {
        for (int j=1;j<i;j++)
        {
            if (i-j<=n && j<=n)
            {
                if (a[j][i-j]<0){a[j][i-j]=0;}
                else {a[j][i-j]=(a[j-1][i-j]+a[j][i-j-1])%100003;}
            }
        }
    }
    cout<<a[n][n];
}