#include<bits/stdc++.h>
using namespace std;

int a[35]={0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long  m;
    cin>>m;
    long long t,v;
    long p;
    long long q;
    long long sum=0;
    int mi=30;
    for (int i=1;i<=m;i++)
    {
        cin>>t>>v;
        if (t==1)
        {
            a[v]++;
            p=pow(2,v);
            sum+=p;
            if (v<mi)
            {
                mi=v;
            }
        }
        else
        {
            if (v==0)
            {
                cout<<"YES"<<endl;
            }
            else if (v>sum || v<pow(2,mi))
            {
                cout<<"NO"<<endl;
            }
            else
            {
                for (int i=29;i>=mi;i--)
                {
                    q=a[i];p =pow(2,i);
                    if (q>0 && v>=p)
                    {
                        v=max(v%p,v-p*q);
                    }
                }
                if (v)
                {
                    cout<<"NO"<<endl;
                }
                else
                {
                    cout<<"YES"<<endl;
                }
            }
        }
    }
    return 0;
}
