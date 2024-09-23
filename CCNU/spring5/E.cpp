#include<bits/stdc++.h>
using namespace std;

bool mysqrt(int n)
{
    int ans=sqrt(n);
    return ans*ans==n;
}
void solve()
{
    int n;
    cin>>n;
    bool flag =false;
    if (n%2==0)
    {
        if (mysqrt(n/2))
        {
            flag=true;
        }
    }
    if (n%4==0)
    {
        if (mysqrt(n/4))
        {
            flag=true;
        }
    }

    if (flag)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
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
        t--;
        solve();
    }
    return 0;
}