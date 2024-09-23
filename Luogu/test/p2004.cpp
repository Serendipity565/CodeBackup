#include<bits/stdc++.h>
using namespace std;
int a[1003][1003]={0};
int main()
{
    int n,m,c;
    cin>>n>>m>>c;
    for (int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
        }
    }
    int sum=a[c][c];
    int p=1,q=1;
    for (int i=c;i<=n;i++)
    {
        for (int j=c;j<=m;j++)
        {
            if (a[i][j]-a[i-c][j]-a[i][j-c]+a[i-c][j-c]>sum)
            {
                sum=a[i][j]-a[i-c][j]-a[i][j-c]+a[i-c][j-c];
                p=i-c+1;
                q=j-c+1;
            }
        }
    }
    cout<<p<<" "<<q;
    return 0;
}