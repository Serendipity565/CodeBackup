#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long b[200005]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    long long sum=0;
    for (int i=1;i<=n-1;i++)
    {
        sum+=a[i]*(b[n]-b[i]);
    }
    cout<<sum;
    return 0;
}