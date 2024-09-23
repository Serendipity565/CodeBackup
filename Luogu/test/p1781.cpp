#include <bits/stdc++.h>
using namespace std;

struct per
{
    string s;
    int s1;
    int num;
}zhong[25];

bool cmp(per a,per b)
{
    if (a.s1>b.s1) return 1;
    else if (a.s1==b.s1 && a.s>b.s) return 1;
    else return 0;
}

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>zhong[i].s;
        zhong[i].num=i;
        zhong[i].s1=zhong[i].s.length();
    }
    sort(zhong+1,zhong+1+n,cmp);
    cout<<zhong[1].num<<endl;
    cout<<zhong[1].s;
    return 0;
}