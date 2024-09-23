#include <bits/stdc++.h>
using namespace std;

struct mon
{
    int w,v;
    double res;
}m[105];

bool cmp(mon a,mon b)
{
    if (a.res>b.res) return 1;
    else return 0;
}

int main()
{
    int n;
    double t;
    int k=0;
    double value=0;
    cin>>n>>t;
    for (int i=0;i<n;i++)
    {
        cin>>m[i].w>>m[i].v;
        m[i].res=m[i].v*1.0/m[i].w;
    }
    sort(m,m+n,cmp);
    while (t>0 && k<=n-1)
    {
        if (t>m[k].w)
        {
            value+=m[k].v;
            t-=m[k].w;
            k++;
        }
        else
        {
            value+=m[k].res*t;
            t=0;
        }
    }
    cout<<fixed<<setprecision(2)<<value;
    return 0;
}