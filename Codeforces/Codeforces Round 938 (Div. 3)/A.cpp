#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n,a,b;
    cin>>n>>a>>b;
    if (n%2==0)
    {
        long long c=min(a*2,b);
        cout<<c*n/2<<endl;
    }
    else
    {
        if (a<=b/2)
        {
            cout<<a*n<<endl;
        }
        else
        {
            cout<<n/2*b+a<<endl;
        }
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
        solve();
        t--;
    }
    return 0;
}