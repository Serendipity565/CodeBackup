#include<bits/stdc++.h>
using namespace std;
int n;
string s;
stack<char> st;
int k=0;
int r=0,c=0;
bool check(string s)//false stand for e
{
    for (int i=0;i<s.length();i++)
    {
        if (s[i]<='9' && s[i]>='0')
        {
            if (s[i+1]=='C')
            {
                return true;
            }
        }
    }
    return false;
}
void e_to_r(string s)
{
    for (int i=0;i<s.length();i++)
    {
        if (s[i]>='A' && s[i]<='Z')
        {
            c*=26;
            c+=s[i]-'A'+1;
        }
        else
        {
            r=r*10+(s[i]-'0');
        }
    }
}
void r_to_e(string s)
{
    int i=1;
    char temp;
    while (s[i]!='C')
    {
        r=r*10+(s[i]-'0');
        i++;
    }
    for (int j=i+1;j<s.length();j++)
    {
        c=c*10+(s[j]-'0');
    }
    while (c>0)
    {
        temp=(c%26-1+26)%26+'A';
        st.push(temp);
        if (temp=='Z')c-=26;
        c/=26;
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        if (check(s))
        {
            r=0;c=0;k=0;
            r_to_e(s);
            while (!st.empty())
            {
                cout<<st.top();
                st.pop();
            }
            cout<<r<<endl;
            
        }
        else
        {
            r=0;c=0;
            e_to_r(s);
            cout<<'R'<<r<<'C'<<c<<endl;
            
        }
    }
    return 0;
}