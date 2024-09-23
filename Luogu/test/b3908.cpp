#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long sum=0;
    long long temp;
    while (n>0)
    {
        n--;
        cin>>temp;
        sum=sum^temp;
    }
    cout<<sum<<" "<<0;
    return 0;
}