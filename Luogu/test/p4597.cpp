#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long ans=0;
    int a[500005];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];   
    }
    //开始处理数据
    int l=0,r=0;
    bool flag=false;
    for (int i=0;i<n-1;i++)
    {
        if (a[i]>a[i+1] && flag==false)
        {
            flag=true;
            l=i+1;
            r=i+1;
            continue;
        }
        if (a[l]>a[i] && flag==true)
        {
            r=i;
        }
        else//此时已经找到异常区间
        {
            for (int i=l;i<=r;i++)
            {
                ans+=min(abs(a[i]-a[l-1]),abs(a[i]-a[r+1]));
            }
            flag=false;
        }
    }
    cout<<ans;
    return 0;
}