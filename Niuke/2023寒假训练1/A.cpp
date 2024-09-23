#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int temp;
    cin>>n;
    int ans=n;
    for (int i=1;i<=n;i++)
    {
        cin>>temp;
        if (temp==1)
        {
            ans--;
        }
    }
    cout<<ans;
    return 0;
}