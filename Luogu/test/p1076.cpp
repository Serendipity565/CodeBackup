#include<bits/stdc++.h>
using namespace std;
const int mymod=20123;
int a[10005][105]={0};
int b[10005]={0};
int main()
{
    int n,m;
    int pas,num;
    int sum=0;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<m;j++)
        {
            scanf("%d %d",&pas,&num);
            a[i][j]=num;
            if (pas==0) a[i][j]*=(-1);
            else b[i]+=1;
        }
    }
    int j;
    scanf("%d",&j);
    for (int i=1;i<=n;i++)
    {
        sum=(abs(a[i][j])+sum)%mymod;
        num=abs(a[i][j])%b[i];
        while (num>0)
        {

            if (a[i][j]>0)
            {
                num--;
            }
            j=(j+1)%m;

        }
        j=(j-1+m)%m;
        while (a[i][j]<0)
        {
            j=(j-1+m)%m;
        }
    }
    printf("%d",sum);
    return 0;
}