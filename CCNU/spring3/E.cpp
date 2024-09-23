#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    stack <int >a;
    int z=0;int j=0;
    for (int i=s.length()-1;i>=0;i--)
    {
        if (s[i]=='b')
        {
            z++;
        }
        else if (s[i]=='B')
        {
            j++;
        }
        else if (s[i]>='a' && s[i]<='z')
        {
            if (z>0)
            {
                z--;
            }
            else
            {
                a.push(i);
            }
        }
        else
        {
            if (j>0)
            {
                j--;
            }
            else
            {
                a.push(i);
            }
        }
    }
    while (!a.empty())
    {
        cout<<s[a.top()];
        a.pop();
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t)
    {
        t--;
        solve();
    }
    return 0;
}