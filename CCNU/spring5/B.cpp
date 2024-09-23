#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    long long sum=1;
    sum+=n*(n-1)*2;
    cout<<sum;
    return 0;
}
