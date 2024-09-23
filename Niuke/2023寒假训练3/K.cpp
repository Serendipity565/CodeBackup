#include<bits/stdc++.h>
using namespace std;
int q[]={0,0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long y;
    cin>>y;
    set<int> res;
    long long x;
    long long sum=0;
    const long long p=1e9+7;
    for (int a=0;a<=9;a++)
    {
        for (int b=0;b<=9;b++)
        {
            if (a!=b) for (int c=0;c<=9;c++)
            {
                if (a!=c && c!=b) for (int d=0;d<=9;d++)
                {
                    if (d!=a && d!=b && d!=c) for (int j=0;j<=9;j++)
                    {
                        long long x=0;
                        for (int i=0;i<n;i++)
                        {
                            if (s[i]>='0' && s[i]<='9')
                            {
                                x=x*10+(s[i]-'0');
                            }
                            else if (s[i]=='_')
                            {
                                x=x*10+j;
                            }
                            else if (s[i]=='a')
                            {
                                x=x*10+a;
                            }
                            else if (s[i]=='b')
                            {
                                x=x*10+b;
                            }
                            else if (s[i]=='c')
                            {
                                x=x*10+c;
                            }
                            else if (s[i]=='d')
                            {
                                x=x*10+d;
                            }
                        }
                        if (x<=y && x%8==0 && x>=q[n])
                        {
                            res.insert(x);
                        }
                    }
                }
            }
        }
    }
    cout<<res.size()%p<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t>0)
    {
        solve();
        t--;
    }
    return 0;
}