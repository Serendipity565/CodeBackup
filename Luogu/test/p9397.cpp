#include<bits/stdc++.h>
using namespace std;

struct sit
{
    int x;
    int y;
    int id;
}s[500005];

bool cmp(sit a,sit b)
{
    if (a.x<b.x) return 1;
    else if (a.x==b.x && a.y>b.y) return 1;
    else return 0;
}

int main()
{
    int n;
    cin>>n;
    if (n%2==1)
    {
        cout<<-1;
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        cin>>s[i].x>>s[i].y;
        s[i].id=i+1;
    }
    sort(s,s+n,cmp);
    long long sum=0;
    for (int i=0;i<n;i+=2)
    {
        sum+=abs(s[i].x-s[i+1].x);
    }
    cout<<sum<<endl;
    for (int i=0;i<n;i+=2)
    {
        cout<<s[i].id<<" "<<s[i+1].id<<endl;
    }
    return 0;
}