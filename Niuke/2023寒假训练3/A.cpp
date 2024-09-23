#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    for (int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int sum=0;
        if (a==150)
        {
            sum++;
        }
        else if (a==200)
        {
            sum+=2;
        }
        if (b==45)
        {
            sum+=2;
        }
        else if(b==36 || b==38 ||b==40 ||b==34)
        {
            sum++;
        }
        if (c==45)
        {
            sum+=2;
        }
        else if(c==36 || c==38 ||c==40 ||c==34)
        {
            sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}