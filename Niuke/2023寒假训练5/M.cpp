#include<bits/stdc++.h>
using namespace std;

int a[100005]={0};
int b[100005]={0};

void solve()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
    }

    if (n==1)
    {
        cout<<"-1"<<endl;
    }
    else if (n==2)
    {
        if (a[1]==b[2])
        {
            cout<<"1"<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
    else
    {
        for (int i=2;i<n;i++)
        {
            if (a[i]==b[i] || a[i]==b[i-1] || a[i]==b[i+1])
            {
                cout<<"1"<<endl;
                return ;
            }
        }
        if (a[1]==b[2] || a[n]==b[n-1])
        {
            cout<<"1"<<endl;
        }
        else
        {
            cout<<"2"<<endl;
        }

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
    return 0;
}