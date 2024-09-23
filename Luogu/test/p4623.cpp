#include<bits/stdc++.h>
using namespace std;
int x[1000006]={0};
int y[1000006]={0};
int main()
{
    int n,m;
    scanf("%d",&n);
    int x1,y1,x2,y2,x3,y3;
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
        x[min(x1,min(x2,x3))+1]++;x[max(x1,max(x2,x3))]--;
        y[min(y1,min(y2,y3))+1]++;y[max(y1,max(y2,y3))]--;
    }
    for (int i=1;i<=1000000;i++)
    {
        x[i]+=x[i-1];
        y[i]+=y[i-1];
    }
    scanf("%d",&m);
    char s,s1;
    int xy;
    for (int i=0;i<m;i++)
    {
        scanf(" %c %c %d",&s,&s1,&xy);
        if (s=='x')
        {
            printf("%d\n",x[xy]);
        }
        else if (s=='y')
        {
            printf("%d\n",y[xy]);
        }
    }
    return 0;
}