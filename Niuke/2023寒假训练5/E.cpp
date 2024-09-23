#include<bits/stdc++.h>
using namespace std;
long long k;
long long a[200005]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n>>k;
    long long ans=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=(a[i]+a[i-1])%k;
    }
    set <int > st;
    int j=0;
    for (int i=1;i<=n;i++)
    {
        if (st.find(a[i]-a[j]+k)!=st.end() || (a[i]-a[j])==0)
        {
            ans++;
            j=i;
            st.clear();
        }
        else
        {
            st.insert(a[i]-a[j]+k);
        }
    }
    cout<<ans<<endl;
    return 0;
}