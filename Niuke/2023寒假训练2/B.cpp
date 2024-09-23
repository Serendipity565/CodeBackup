#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        int n;
        scanf("%d",&n);
        bool a1[1000000004]={0};bool a2[1000000004]={0};
        bool b1[1000000004]={0};bool b2[1000000004]={0};
        int x,y;       
        for (int i=1;i<=n;i++)
        {
            scanf(" %d %d",&x,&y);
            if (x==1)
            {
                if (y>=0)
                {
                    a2[y]=1;
                }
                else 
                {
                    a1[-y]=1;
                }
            }
            else
            {
                if (y>=0)
                {
                    b2[y]=1;
                }
                else b1[-y]=1;
            }
        }
        t--;
    }
}