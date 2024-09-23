#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    int sum=0;
    int a[30]={0};
    int m=s.length();
    for (int i=0;i<min(n,m);i++)
    {
        a[s[i]-'A'+1]++;
    }
    for (int i=1;i<=26;i++)
    {
        if (a[i]>=i)
        {
            sum++;
        }
    }
    cout<<sum<<endl;
}

int main()
{
    int t;
    cin>>t;
    while (t)
    {
        t--;
        solve();
    }   
}