#include<bits/stdc++.h>
using namespace std;
int a[200005]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long sum=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if (n==1)
    {
        cout<<1;
        return 0;
    }
    long long cnt=sum/n;
    long long ans=0;
    for (long long i=1;i<=cnt;i++)
    {
        if (sum%i==0)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}