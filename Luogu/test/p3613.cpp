#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    int f,i,j,k;
    vector<vector<int> > a(n+1);
    for (int r=0;r<q;r++)
    {
        cin>>f;
        if (f==1)
        {
            cin>>i>>j>>k;
            if(a[i].size()<j+1) a[i].resize(j+1);
            a[i][j]=k;
        }
        else
        {
            cin>>i>>j;
            cout<<a[i][j]<<endl;
        }
    }
    return 0;
}
