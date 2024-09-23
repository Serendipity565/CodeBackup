#include <bits/stdc++.h>
using namespace std;

struct vol
{
    int num;
    int score;
}volunt[5005];

bool cmp(vol a,vol b)
{
    if (a.score>b.score) return 1;
    else if (a.score<b.score) return 0;
    else
    {
        if (a.num<b.num) return 1;
        else return 0;
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    m=m*1.5;
    for (int i=0;i<n;i++)
    {
        cin>>volunt[i].num>>volunt[i].score;
    }
    sort(volunt,volunt+n,cmp);
    while (1)
    {
        if (volunt[m-1].score==volunt[m].score) m++;
        else break;
    }
    cout<<volunt[m-1].score<<" "<<m<<endl;
    for (int i=0;i<m;i++)
    {
        cout<<volunt[i].num<<" "<<volunt[i].score<<endl;
    }
    return 0;
}