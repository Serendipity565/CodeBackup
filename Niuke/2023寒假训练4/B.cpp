#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t)
    {
        int n;
        int temp;
        scanf(" %d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf(" %d",&temp);
        }
        if (n%2==0)
        {
            printf("zn\n");
        }
        else
        {
            printf("qcjj\n");
        }
        t--;
    }
    return 0;
}