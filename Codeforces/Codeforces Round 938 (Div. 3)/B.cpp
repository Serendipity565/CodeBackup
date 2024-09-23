#include<bits/stdc++.h>
using namespace std;
int a[300005]={0};
int k[300005]={0};
void solve()
{
    memset(a,0,sizeof(a));
    memset(k,0,sizeof(k));
    int n,c,d;
    cin>>n>>c>>d;
    bool flag=true;
    long long temp;
    for (int i=0;i<n*n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n*n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            k[i*n+j]=a[0]+i*c+j*d;
        }
    }
    sort(k,k+n*n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (k[i*n+j]!=a[i*n+j])
            {
                flag=false;
                break;
            }
        }
        if (flag==false)
        {
            break;
        }
    }
    if (flag==true)
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
        solve();
        t--;
    }
    return 0;
}