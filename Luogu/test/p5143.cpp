#include <bits/stdc++.h>
using namespace std;

struct sit
{
    double x,y,z;
}sits[50005];

bool cmp(sit a,sit b)
{
    if (a.z>b.z) return 1;
    else return 0;
}

double distance(sit a,sit b)
{
    double ans;
    ans=pow(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2),0.5);
    return ans;
}

int main()
{
    int n;
    double res=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>sits[i].x>>sits[i].y>>sits[i].z;
    }
    sort(sits,sits+n,cmp);
    for (int i=0;i<n-1;i++)
    {
        res+=distance(sits[i],sits[i+1]);
    }
    cout<<fixed<<setprecision(3)<<res;
    return 0;
}