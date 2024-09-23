#include<bits/stdc++.h>
using namespace std;
int t;
int a[30004]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t>0)
    {
        int n;
        cin>>n;
        int m[5]={0};
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            m[a[i]%3]++;
        }
        int q=n/3;
        int sum=0;
        for (int i=0;i<=2;i++)
        {
            if (m[i]>q)
            {
                sum+=m[i]-q;
                m[(i+1)%3]+=m[i]-q;
                m[i]=q;
            }
            else if (m[i]<q)
            {
                sum+=q-m[i];
                m[(i+2)%3]+=m[i]-q;
                m[i]=q;
            }
        }
        cout<<sum<<endl;
        t--;
    }
    return 0;
}