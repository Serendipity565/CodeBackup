#include<bits/stdc++.h>
using namespace std;
bool check(int a,int k)
{
    int b=a;
    int cnt=0;
    while (b!=0)
    {
        cnt+=b&1;
        b>>=1;
    }
    return cnt==k;
}
int main()
{
    int n,k;
    long long sum=0;
    cin>>n>>k;
    int temp;
    int mp[10004]={0};
    for (int i=1;i<=n;i++)
    {
        cin>>temp;
        mp[temp]++;
    }
    if (k==0)
    {
        for (int i=0;i<=10000;i++)
        {
            if (mp[i]>0)
            {
                sum+=mp[i]*(mp[i]-1);
            }
        }
        sum/=2;
    }
    else
    {
        for (int i=0;i<10000;i++)
        {
            if (mp[i]>0)
            {
                for (int j=i+1;j<=10000;j++)
                {
                    if (mp[j]>0)
                    {
                        if (check(i^j,k))
                        {
                            sum+=mp[i]*mp[j];
                        }
                    }
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}