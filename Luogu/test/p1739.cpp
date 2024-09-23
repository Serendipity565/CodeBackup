#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int len=s.length();
    stack<char> m;
    for (int i=0;i<len;i++)
    {
        if (s[i]=='(')
        {
            m.push(s[i]);
        }
        else if (s[i]==')')
        {
            if (m.size()==0)
            {
                cout<<"NO";
                return 0;;
            }
            else
            {
                m.pop();
            }
        }
    }
    if (m.size()==0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}