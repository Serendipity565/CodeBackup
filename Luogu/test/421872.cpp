#include<bits/stdc++.h>
using namespace std;
int t;
int a[105]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t>0)
    {
        int n,m;
        int sum=0;
        cin>>n>>m;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            if (m-a[i]>=0)
            {
                m-=a[i];
            }
            else
            {
                sum+=a[i]-m;
                m=0;
            }
        }
        cout<<sum<<endl;
        t--; 
    }
    return 0;
}