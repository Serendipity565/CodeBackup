#include<bits/stdc++.h>
using namespace std;

struct cow
{
    int p,a;
}cows[5005];
bool cmp(cow a,cow b)
{
    return a.p<b.p;
}
int main()
{
    int n,m;
    int sum=0;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        cin>>cows[i].p>>cows[i].a;
    }
    sort(cows,cows+m,cmp);
    int k=0;
    while (n>0)
    {
        if (n>=cows[k].a)
        {
            sum+=cows[k].p*cows[k].a;
            n-=cows[k].a;
            k++;
        }
        else
        {
            sum+=n*cows[k].p;
            n=0;
        }
    }
    cout<<sum;
    return 0;
}