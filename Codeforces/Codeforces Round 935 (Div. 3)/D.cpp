#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
void solve()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    long long n ,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin>>b[i];
    } 
    long long sum=a[m];
    for (int i=n;i>m;i--)
    {
        sum+=min(a[i],b[i]);
    }
    long long ans=sum;
    for (int i=m;i>1;i--)
    {
        ans=ans-a[i]+min(a[i],b[i])+a[i-1];
        if (ans<sum)
        {
            sum=ans;
        }

    }

    cout<<sum<<endl;

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