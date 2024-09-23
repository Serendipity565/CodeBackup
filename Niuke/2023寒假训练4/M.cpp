#include<bits/stdc++.h>
using namespace std;
unsigned long long a[100005]={0};
bool check(unsigned long long i,unsigned long long j)
{
    unsigned long long k=0;
    int p = 0;
    unsigned long long temp = j;
    while (temp != 0) {
        temp /= 10;
        p++;
    }
    k = i * static_cast<unsigned long long>(pow(10, p)) + j;
    if (k%36==0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    unsigned long long sum=0;
    for (int i=1;i<=t;i++)
    {
        scanf("%llu",&a[i]);
    }
    for (int i=1;i<=t;i++)
    {
        if (a[i]%1==1)
        {
            continue;
        }
        for (int j=1;j<=t;j++)
        {
            if (i!=j && check(a[j],a[i]))
            {
                sum++;
            }
        }
    }
    printf("%llu",sum);
    return 0;
}