#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n,m;
    cin>>n>>m;
    long long m1=m,m2=m;
    long long time,hi,li;
    long long temp=0;
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        cin>>time>>li>>hi;
        if ((m1+(time-temp)>=li && m1+(time-temp)<=hi) || (m2-(time-temp)>=li && m2-(time-temp)<=hi) 
        ||  (m1+(time-temp)>=li && m2-(time-temp)<=li) || (m1+(time-temp)>=hi && m2-(time-temp)<=hi))
        {
            m1=min(hi,m1+(time-temp));
            m2=max(li,m2-(time-temp));
        }
        else
        {
            flag=false;
        }
        temp=time;
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
}