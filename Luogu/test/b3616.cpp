#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a,b;
    queue<int> q;
    for (int i=1;i<=n;i++)
    {
        cin>>a;
        if (a==1)
        {
            cin>>b;
            q.push(b);
        }
        else if(a==2)
        {
            if (q.size()==0) cout<<"ERR_CANNOT_POP"<<endl;
            else q.pop();
        }
        else if(a==3)
        {
            if (q.size()==0) cout<<"ERR_CANNOT_QUERY"<<endl;
            else cout<<q.front()<<endl;
        }
        else
        {
            cout<<q.size()<<endl;
        }
    }
    return 0;
}