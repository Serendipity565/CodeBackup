#include<bits/stdc++.h>
using namespace std;

struct minister
{
    int a;
    int b;
}ministers[1005];

bool cmp(minister m,minister n)
{
    return (max(1/m.b,m.a/n.b)<max(1/n.b,n.a/m.b));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    minister king;
    cin>>king.a>>king.b;
    for (int i=0;i<n;i++)
    {
        cin>>ministers[i].a>>ministers[i].b;
    }
    sort(ministers,ministers+n,cmp);
    long long mymax=0;
    long long ans=king.a;
    for (int i=0;i<n;i++)
    {
        if (ans/ministers[i].b>mymax)
        {
            mymax=ans/ministers[i].b;
        }
        ans*=ministers[i].a;
    }
    cout<<mymax;
    return 0;
}