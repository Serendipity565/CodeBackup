#include<bits/stdc++.h>
using namespace std;

string change(string s)
{
    string s1;
    for (int i=0;i<s.length()-1;i++)
    {
        if (s[i]>s[i+1])
        {
            s1.assign(s,0,i);
            s1.append(s,i+1,s.length()-1);
            return s1;
        }
    }
    return s;
}

int main()
{
    string s,s1;
    int n;
    cin>>s>>n;
    for (int k=0;k<n;k++)
    {
        if (s!=change(s))
        {
            s=change(s);
        }
        else
        {
            s.assign(s,0,s.length()-1);
        }
    }
    //删除前缀0
    while (s[0]=='0' && s.length()>1)
    {
        s.assign(s,1,s.length()-1);
    }
    cout<<s;
    return 0;
}