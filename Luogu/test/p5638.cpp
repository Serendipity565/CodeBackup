#include<bits/stdc++.h>
using namespace std;
long long a[1000006];
long long b[1000006]={0};
long long sum=0;
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if (i<=k)
        {
            b[1]+=a[i];
        }
    }

    if (k==0)
    {
        cout<<sum;
        return 0;
    }

    for(int i=2;i<=n-k;i++)
    {
        b[i]=b[i-1]+a[i+k-1]-a[i-1];
    }


    long long mymax=b[1];
    for (int i=2;i<=n-k;i++)
    {
        if (b[i]>mymax) mymax=b[i];
    }

    cout<<sum-mymax;

    return 0;
}