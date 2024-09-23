#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    priority_queue<long long,vector<long long>,greater<long long> > q;
    int op;
    long long a;
    for (int i=1;i<=n;i++)
    {
        cin>>op;
        if (op==1)
        {
            cin>>a;
            q.push(a);
        }
        else if (op==2)
        {
            cout<<q.top()<<endl;
        }
        else
        {
            q.pop();
        }
    }
    return 0;
}