#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int w,n;
    cin>>w>>n;
    int a[30005];
    int ans=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int i=0;int j=n-1;
    while (i<j)
    {
        if (a[i]+a[j]>w)
        {
            j--;
            ans++;
        }
        else
        {
            i++;j--;
            ans++;
        }
    }
    if (i==j)
    {
        ans++;
    }
    cout<<ans;
    return 0;
}