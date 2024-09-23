#include<bits/stdc++.h>
using namespace std;
char a[505][505];
int n,m;
int check(int i,int j)
{
    int ans=0;
    int k=1;
    int x=i;int y=j;
    while (x+k<n && y-k>=0 && y+k<m)
    {
        if (a[x+k][y-k]=='*' && a[x+k][y+k]=='*')
        {
            ans++;
            for (int i=y-k+1;i<y+k;i++)
            {
                if(a[x+k][i]=='.')
                {
                    ans--;
                    break;
                }
            }
            k++;
        }
        else
        {
            break;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long sum=0;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (a[i][j]=='*')
            {
                sum+=check(i,j);
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}