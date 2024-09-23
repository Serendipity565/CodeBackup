#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        if (s1[0]==s2[0] || abs(int(s1[0])-int(s2[0]))==32 )
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        t--;
    }
    return 0;
}