#include<bits/stdc++.h>
using namespace std;
int a[1000005]={0};
bool zhishu(int n)
{
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0) return 0;
    }
    return 1;
}
int main()
{
    int n,m;
    cin>>n>>m;
    a[2]=1;
    for (int i=3;i<=m;i++)
    {
        if (zhishu(i))
        {
            a[i]=a[i-1]+1;
        }
        else
        {
            a[i]=a[i-1];
        }
    }
    int l,r;
    for (int i=0;i<n;i++)
    {
        cin>>l>>r;
        if (r>m || l<1)
        {
            cout<<"Crossing the line"<<endl;
        }
        else
        {
            cout<<a[r]-a[l-1]<<endl;
        }
    }
    return 0;
}