#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int a[100005];
    long long res=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++)
    {
        if (a[i]+a[i+1]>x)
        {
            res+=a[i]+a[i+1]-x;
            a[i+1]=x-a[i];
        }
    }
    cout<<res;
    return 0;
}