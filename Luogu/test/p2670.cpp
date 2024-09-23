#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int b[105][105]={0};
int main()
{
	int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            char s;
            scanf("%c",&s);
            if(s!='\n') a[i][j]=s;
            else scanf("%c",&a[i][j]);
        }
    }
    for (int i =1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]=='*')
            {
                b[i][j]=-1;
                for (int p=i-1;p<=i+1;p++)
                {
                    for (int q=j-1;q<=j+1;q++)
                    {
                        if (b[p][q]>=0 && !(p==i && q==j)) b[p][q]++;
                    }
                }
            }
        }
    }
    for (int i =1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if(b[i][j]<0) printf("*");
            else printf("%d",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}