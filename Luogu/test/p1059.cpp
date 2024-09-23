#include <bits/stdc++.h>
using namespace std;

int a[1010]={0};
int b[110]={0};
int main()
{
    int n,m,j=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>m;
        a[m]++;
    }
    for (int i=1;i<=1000;i++)
    {
        if (a[i]>0)
        {
            b[j]=i;
            j++;
        }
    }
    sort(b,b+105);
    cout<<j<<endl;
    for (int i=0;i<=105;i++)
    {
        if (b[i]>0)
        {
            cout<<b[i]<<" ";
        }
    }
    return 0;
}