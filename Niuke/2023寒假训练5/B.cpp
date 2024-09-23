#include<bits/stdc++.h>
using namespace std;
int a[200005]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long sum=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i]-1;
    }
    if (sum%2==0)
    {
        cout<<"sweet"<<endl;
    }
    else
    {
        cout<<"gui"<<endl;
    }
    return 0;
}