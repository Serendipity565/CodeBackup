#include<bits/stdc++.h>
using namespace std;
int y[1000006]={0};
int b[1000006]={0};
int r[1000006]={0};
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int li,ri,ki;
    for (int i=0;i<m;i++)
    {
        scanf("%d %d %d",&li,&ri,&ki);
        if (ki==1)
        {
            y[li]+=1;
            y[ri+1]-=1;
        }
        else if (ki==2)
        {
            b[li]+=1;
            b[ri+1]-=1;
        }
        else
        {
            r[li]+=1;
            r[ri+1]-=1;
        }
    }
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        y[i]+=y[i-1];
        b[i]+=b[i-1];
        r[i]+=r[i-1];
        if (y[i] && b[i] && (!r[i]))
        {
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}