#include<bits/stdc++.h>
using namespace std;
char a[110][110];
int b[110][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int p,q;
    cin>>p>>q;
    int op,z;
    for (int i=0;i<q;i++)
    {
        cin>>op>>z;
        b[i][0]=op;
        b[i][1]=z;
    }
    char temp;
    for (int i=0;i<p;i++)
    {
        for (int j=0;j<q;j++)
        {
            if (b[j][0]==1)
            {
                temp=a[b[j][1]-1][m-1];
                for (int k=m-1;k>0;k--)
                {
                    a[b[j][1]-1][k]=a[b[j][1]-1][k-1];
                }
                a[b[j][1]-1][0]=temp;
            }
            else
            {
                temp=a[n-1][b[j][1]-1];
                for (int k=n-1;k>0;k--)
                {
                    a[k][b[j][1]-1]=a[k-1][b[j][1]-1];
                }
                a[0][b[j][1]-1]=temp;
            }
        }
    }
    cout<<a[x-1][y-1]<<endl;
    return 0;
}