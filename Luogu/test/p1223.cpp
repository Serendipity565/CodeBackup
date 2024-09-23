#include <bits/stdc++.h>
using namespace std;

struct time_1
{
    int num;
    int t;
}ti[1005];

bool cmp(time_1 a,time_1 b)
{
    if (a.t<b.t) return 1;
    else return 0;
}

int main()
{
    int n;
    cin>>n;
    double sum=0;
    multimap<int,int> mp;
    for (int i=0;i<n;i++)
    {
        cin>>ti[i].t;
        ti[i].num=i+1;
    }
    sort(ti,ti+n,cmp);
    for (int i=0;i<n;i++)
    {
        sum+=ti[i].t*(n-i-1);
        cout<<ti[i].num<<" ";
    }
    cout<<endl;
    cout<<fixed<<setprecision(2)<<sum/n;
    return 0;
}