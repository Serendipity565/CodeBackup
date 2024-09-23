#include <bits/stdc++.h>
using namespace std;

int a[20005]={0};

bool cmp(int a,int b)
{
    if (a>b) return 1;
    else return 0;
}

int main()
{
    int n;
    long long sum,ans=0;
    cin>>n;
    cin>>sum;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for (int i=0;i<n;i++)
    {
        ans+=a[i];
        if (ans>=sum)
        {
        cout<<i+1;
        break;
        }
    }
    return 0;
}