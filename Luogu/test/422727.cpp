#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t>0)
    {
        long long a,m,b,s;
        cin>>a>>b>>m>>s;
        if (a*m+b<s)
        {
            cout<<"NO"<<endl;
        }
        else if (a*m+b==s)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            long long c=s/m;
            c=min(c,a);
            if (s-c*m<=b)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        t--; 
    }
    return 0;
}