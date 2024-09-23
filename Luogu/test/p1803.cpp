#include <bits/stdc++.h>
using namespace std;

struct match
{
    int start;
    int end;
}m[1000006];

bool cmp(match a,match b)
{
    if (a.end<b.end) return 1;
    else return 0;
}

int main()
{
    int n,res,ans=1;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>m[i].start>>m[i].end;
    }
    sort(m,m+n,cmp);
    res=m[0].end;
    for (int i=1;i<n;i++)
    {
        if (m[i].start>=res)
        {
            ans++;
            res=m[i].end;
        }
    }
    cout<<ans;
    return 0;
}