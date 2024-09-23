#include<bits/stdc++.h>
using namespace std;
int r;
int a[1010][1010]={0};
int main()
{
    scanf("%d",&r);
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
        }
    }
    int mymax=0;
    for (int i=1;i<=r;i++)
    {
        if (a[r][i]>mymax) mymax=a[r][i];
    }
    printf("%d",mymax);
    return 0;
}