#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int l=0,r;
    long long ans=0;
    while (l<=n-1)
    {
        int min=a[l];
        r=l;
        for (int i=l;i<n;i++)
        {
            if (a[i]==0)
            {
                r=i-1;
                break;
            }
            else if (a[i]<min) 
            {
                r=i;
                min=a[i];
            }
            else r=i;
        }
        ans+=min;
        for (int i=l;i<=r;i++)
        {
            a[i]-=min;
        }
        while (a[l]==0 && l<=n-1) l++;
    }
    cout<<ans;
    return 0;
}