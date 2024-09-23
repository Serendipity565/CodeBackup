#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t,a,k;
    long long ans=0;
    cin>>t>>a>>k;
    if(t>0)
    {
        if (a>=-k && a<=t+k)
        {
            ans+=abs(a);
            ans+=abs(t-a);
        }
        else
        {
            ans+=abs(t);
            ans+=abs(t-a)*2;
        }
    }
    else
    {
        if (a>=t-k && a<=k)
        {
            ans+=abs(a);
            ans+=abs(t-a);
        }
        else
        {
            ans+=abs(t);
            ans+=abs(t-a)*2;
        }
    }
    cout<<ans<<endl;
    return 0;
}