#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t>0)
    {
        int n;
        string s;
        cin>>n;
        string s1="DFS";int q1=0;
        string s2="dfs";int q2=0;
        cin>>s;
        for (int i=0;i<n;i++)
        {
            if (s[i]==s1[q1])
            {
                q1++;
            }
            if (s[i]==s2[q2])
            {
                q2++;
            }
        }
        if (q1==3)
        {
            cout<<1<<" ";
        }
        else{
            cout<<0<<" ";
        }
        if (q2==3)
        {
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
        t--;
    }
    return 0;
}