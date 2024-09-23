#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        t--;
        long long a,b;
        scanf(" %lld %lld",&a,&b);
        if (a==b)
        {
            printf("0\n");
        }
        else
        {
            long long c=a^b;
            int cnt=0;
            if ((c & a)>0)
            {
                cnt++;
            }
            if ((c & b)>0)
            {
                cnt++;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}