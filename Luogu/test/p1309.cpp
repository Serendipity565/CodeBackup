#include <bits/stdc++.h>
using namespace std;

struct stu
{
    int num;
    int socre;
    int p;
};

stu student[200005];
stu tempwin[100005];
stu templost[100005];

void msort(int l,int r)
{
    int win=l,lost=l;
    int k=1;
    r/=2;
    while (win<=r && lost<=r)
    {
        if (tempwin[win].socre>templost[lost].socre)
        {
            student[k]=tempwin[win];
            k++;win++;
        }
        else if (tempwin[win].socre<templost[lost].socre)
        {
            student[k]=templost[lost];
            k++;lost++;
        }
        else 
        {
            if (tempwin[win].num<templost[lost].num)
            {
                student[k]=tempwin[win];
                k++;win++;
            }
            else
            {
                student[k]=templost[lost];
                k++;lost++;
            }
        }
    }
    while (win<=r)
    {
        student[k]=tempwin[win];
        k++;win++;
    }
    while (lost<=r)
    {
        student[k]=templost[lost];
        k++;lost++;
    }
    return;
}

bool cmp(stu a,stu b)
{
    if (a.socre != b.socre) return a.socre>b.socre;
    else return a.num<b.num;
}

int main()
{
    int n,r,q;
    cin>>n>>r>>q;
    n*=2;
    for (int i=1;i<=n;i++)
    {
        student[i].num=i;
        cin>>student[i].socre;
    }
    for (int i=1;i<=n;i++)
    {
        cin>>student[i].p;
    }
    sort(student+1,student+1+n,cmp);
    for (int i=1;i<=r;i++)
    {
        int u=1;
        for (int j=1;j<=n;j+=2)
        {
            if (student[j].p>student[j+1].p)
            {
                student[j].socre++;
                tempwin[u]=student[j];
                templost[u]=student[j+1];
                u++;
            }
            else
            {
                student[j+1].socre++;
                tempwin[u]=student[j+1];
                templost[u]=student[j];
                u++;
            }
        }
        msort(1,n);
    }
    cout<<student[q].num;
    return 0;
}