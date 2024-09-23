#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m,k,p;
    cin>>n>>m>>k>>p;
    long long max1=k/p;
    if (max1>m) max1=m;
    long long res=k-max1*p;
    if (n==p)
    {
        if (k%p==0)
        {
            cout<<"YES"<<endl;
            for (long long i=0;i<n;i++)
            {
                cout<<max1<<" "<<m-max1<<endl;
            }
            return 0;
        }
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    if (res/(n-p)>=max1) cout<<"NO";
    else
    {
        if (res/(n-p)==max1-1 && res%(n-p)>0) cout<<"NO";
        else
        {
            cout<<"YES"<<endl;
            for (long long i=0;i<p;i++)
            {
                cout<<max1<<" "<<m-max1<<endl;
            }
            for (long long i=0;i<res%(n-p);i++)
            {
                cout<<res/(n-p)+1<<" "<<m-res/(n-p)-1<<endl;
            }
            for (long long i=res%(n-p);i<n-p;i++)
            {
                cout<<res/(n-p)<<" "<<m-res/(n-p)<<endl;
            }
        }
    }
    return 0;
}