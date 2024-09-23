#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n;
    long long sum=0;
    priority_queue<int,vector<int>,greater<int> >q;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        q.push(a);
    }
    for (int i=0;i<n-1;i++)
    {
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        sum+=a+b;
        q.push(a+b);
    }
    cout<<sum;
    return 0;
}