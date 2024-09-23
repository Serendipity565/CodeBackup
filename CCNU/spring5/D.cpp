#include<bits/stdc++.h>
using namespace std;
int l[200005]={0};
int r[200005]={0};
bool flag;
void check(int a,int b)
{
    if (a==b)
    {
        flag=false;
    }
    else if (l[a]==0 && l[b]==0)
    {
        l[a]=1;
        l[b]=1;
    }
    else if(r[a]==0 && r[b]==0)
    {
        r[a]=1;
        r[b]=1;
    }
    else
    {
        flag=false;
    }
    return ;
}

void solve()
{
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    flag=true;
    int n;
    cin>>n;
    int a,b;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>b;
        check(a,b);
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
    int t;
    cin>>t;
    while (t)
    {
        t--;
        solve();
    }   
}