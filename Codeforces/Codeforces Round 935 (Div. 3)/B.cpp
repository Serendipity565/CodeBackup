#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long a,b,m;
    cin>>a>>b>>m;
    long long sum=2;
    sum+=m/a+m/b;
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