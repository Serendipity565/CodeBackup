#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int win;
    int def;
    for (int i=0;i<=n;i++)
    {
        win=i;
        def=n-i;
        if (win-def==x)
        {
            cout<<win<<" "<<def<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}