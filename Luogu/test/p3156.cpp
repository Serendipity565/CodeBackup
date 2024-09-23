#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> p;
    for (int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        p.push_back(a);
    }
    for (int i=0;i<m;i++)
    {
        int b;
        cin>>b;
        cout<<p[b-1]<<endl;
    }
    return 0;
}