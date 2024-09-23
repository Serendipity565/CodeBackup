#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int x,y;
    int a[10]={0};
    for (int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if (x>0 && y>0)
        {
            a[1]++;
        }
        else if (x>0 && y<0)
        {
            a[4]++;
        }
        else if (x<0 && y>0)
        {
            a[2]++;
        }
        else if (x<0 && y<0)
        {
            a[3]++;
        }
        else if (x==0)
        {
            if (y>0)
            {
                a[6]++;
            }
            else if (y<0)
            {
                a[8]++;
            }
        }
        else if (y==0)
        {
            if (x>0)
            {
                a[5]++;
            }
            else if (x<0)
            {
                a[7]++;
            }
        }
    }
    if (!a[1] && !a[6] && !a[2])
    {
        cout<<"YES"<<endl;
    }
    else if (!a[1] && !a[5] && !a[4])
    {
        cout<<"YES"<<endl;
    }
    else if (!a[4] && !a[8] && !a[3])
    {
        cout<<"YES"<<endl;
    }
    else if (!a[3] && !a[7] && !a[2])
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