#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long a,b,c;
    cin>>a>>b>>c;
    long long sum=0;
    if ((3-(b)%3)>c && b%3!=0)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        sum=a+(b+c)/3;
        if ((b+c)%3!=0)
        {
            sum+=1;
        }
        cout<<sum<<endl;
    }
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