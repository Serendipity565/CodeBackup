#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t>0)
    {
        int n;
        cin>>n;
        int cnt=n/6;
        if (n%6!=0)
        {
            cnt*=2;
        }
        if (cnt==0)
        {
            cnt++;
        }
        cout<<cnt<<endl;
        t--;
    }
    return 0;
}