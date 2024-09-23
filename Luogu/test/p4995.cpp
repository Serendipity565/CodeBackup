#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long res=0;
    int a[305];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    a[n]=0;
    sort(a,a+n+1);
    int i=0;int j=n;
    int k=0;
    while (i!=j)
    {
        res+=pow(a[i]-a[j],2);
        if (k%2==0)
        {
            i++;
            k++;
        }
        else
        {
            j--;
            k++;
        }
    }
    cout<<res;
    return 0;
}