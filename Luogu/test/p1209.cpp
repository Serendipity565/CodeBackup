#include<bits/stdc++.h>
using namespace std;

int a[202];
int main()
{
    int m,s,c;
    cin>>m>>s>>c;
    for (int i=0;i<c;i++)
    {
        cin>>a[i];
    }
    sort(a,a+c);
    int sum=a[c-1]-a[0]+1;
    int b[202],n=0;
    for (int i=0;i<c-1;i++)
    {
        if (a[i]!=a[i+1]-1)
        {
            b[n]=a[i+1]-a[i]-1;
            n++;
        }
    }
    if(n==0)
    {
        cout<<sum;
        return 0;
    }
    sort(b,b+n);
    for (int i=0;i<m-1;i++)
    {
        sum-=b[n-1];
        n--;
        if (n==0)break;
    }
    cout<<sum;
    return 0;
}