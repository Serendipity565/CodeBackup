#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string name_1;
    cin>>n;
    multiset <string> name;
    for (int i=0;i<n;i++)
    {
        cin>>name_1;
        name.insert(name_1);
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++)
    {
        cin>>name_1;
        if (name.count(name_1)==1)
        {
            cout<<"OK"<<endl;
            name.insert(name_1);
        }
        else if (name.count(name_1)>1)
        {
            cout<<"REPEAT"<<endl;
        }
        else
        {
            cout<<"WRONG"<<endl;
        }
    }
    return 0;
}