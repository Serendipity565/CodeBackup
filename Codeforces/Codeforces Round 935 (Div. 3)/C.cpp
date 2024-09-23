#include<bits/stdc++.h>
using namespace std;
int a[300005]={0};

void solve()
{
    memset(a,0,sizeof(a));
    int n;string s;
    int ans;
    cin>>n;
    cin>>s;
    ans=n;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='1')
        {
            a[i+1]=1;
        }
        a[i+1]=a[i+1]+a[i];
    }
    for (int i=0;i<=n;i++)
    {
        if ((i-a[i])>=i/2.0  && (a[n]-a[i])>=(n-i)/2.0)
        {
            if (abs(n/2.0-i)<abs(n/2.0-ans))
            {
                ans=i;
            }
            else if (abs(n/2.0-i)==abs(n/2.0-ans) && i==0)
            {
                ans=i;
            }
        }
    }
    cout<<ans<<endl;

    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}