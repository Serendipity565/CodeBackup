#include<bits/stdc++.h>
using namespace std;
struct g1
{
    int h;
    int p;
}g[100005];

bool cmp(g1 a,g1 b)
{
    return a.p<b.p;
}

void solve()
{
    long long n,k;
    bool flag=true;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>g[i].h;
    }
    for (int i=1;i<=n;i++)
    {
        cin>>g[i].p;
    }
    sort (g+1,g+n+1,cmp);
    int i=1;
    long long ans=k;
    while(i<=n)
    {
        if (g[i].h>k)
        {
            ans-=g[i].p;
            k=k+ans;
        }
        else
        {
            i++;
        }
        if (ans<0)
        {
            flag=false;
            break;
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
        t--;
        solve();
    }   
}