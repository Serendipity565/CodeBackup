#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        stack<unsigned long long> s;
        int m;
        unsigned long long b;
        cin>>m;
        string a;
        for (int j=1;j<=m;j++)
        {
            cin>>a;
            if (a=="push")
            {
                cin>>b;
                s.push(b);
            }
            else if (a=="query")
            {
                if (s.size()==0) cout<<"Anguei!"<<endl;
                else cout<<s.top()<<endl;
            }
            else if (a=="pop")
            {
                if (s.size()==0) cout<<"Empty"<<endl;
                else s.pop();
            }
            else
            {
                cout<<s.size()<<endl;
            }
        }
    }
    return 0;
}