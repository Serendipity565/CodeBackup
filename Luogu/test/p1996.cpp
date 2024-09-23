#include <bits/stdc++.h>
using namespace std;

int a[105]={0};

int main()
{
    int n,m;
    int j=0,sum=0;
    cin>>n>>m;
    bool flag=true;
    for (int i=0;i<n;i++)
    {
        a[i]=i;
    }
    for (int i=1;i<=n;i++)
    {
        while (flag==true)
        {
            if (a[j]>=0)
            {
                sum=(sum+1)%m;
                if (sum==0)
                {
                    cout<<j+1<<" ";
                    a[j]=-1;
                    flag=false;
                    break;
                }
                j=(j+1)%n;
            }
            else j=(j+1)%n;
        }
        flag=true;
    }
    return 0;
}