#include<bits/stdc++.h>
using namespace std;
int a[200005]={0};

void solve()
{
    memset(a,0,sizeof(a));
    int n,k;
    cin>>n>>k;
    long long mymax=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        mymax+=a[i];
    }
    int l=1,r=n;
    long long sum=0;
    int ans=0;
    if (k>=mymax)
    {
        cout<<n<<endl;
        return ;
    }
    while(sum<=k && l<=r)
    {
        if (a[l]<=a[r])
        {
            sum+=a[l]*2;
            a[r]-=a[l];
            l++;
            if (sum==k+1)
            {
                ans++;
            }
        }
        else
        {
            sum+=a[r]*2;
            a[l]=a[l]-a[r];
            r--;
        }
        ans+=1;
    }
    cout<<ans-1<<endl;
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