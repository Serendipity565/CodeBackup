#include <bits/stdc++.h>
using namespace std;

struct oi
{
    string name;
    int y;
    int m;
    int d;
    int num;
    int sum;
}oii[110];

bool cmp(oi a,oi b)
{
    if (a.sum<b.sum) return 1;
    else if (a.sum>b.sum) return 0;
    else
    {
        if (a.num>b.num) return 1;
        else return 0;
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>oii[i].name>>oii[i].y>>oii[i].m>>oii[i].d;
        oii[i].num=i;
        oii[i].sum=oii[i].y;
        oii[i].sum=oii[i].sum*100+oii[i].m;
        oii[i].sum=oii[i].sum*100+oii[i].d;
    }
    sort(oii,oii+n,cmp);
    for (int i=0;i<n;i++)
    {
        cout<<oii[i].name<<endl;
    }
    return 0;
}