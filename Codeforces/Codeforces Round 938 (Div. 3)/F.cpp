#include<bits/stdc++.h>
using namespace std;
int check(int a,int b,int c)
{
    int ans=0;
    if (a%2==1)
    {
        ans++;
    }
    if (b%2==1)
    {
        ans++;
    }
    if (c%2==1)
    {
        ans++;
    }
    return ans;
}
void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=0;
    if (check(a,b,c)==3)
    {
        ans++;
    }
    ans+=a/2+b/2+c/2+d/2;
    cout<<ans<<endl;
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