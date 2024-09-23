#include<bits/stdc++.h>
using namespace std;

struct dian
{
    long long num;
    long long id;
}a[200005];

bool cmp(dian a,dian b)
{
    return a.num<b.num;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int k=1;k<=t;k++)
    {
        long long b[200005]={0};//用于按顺序输出
        int n;
        long long sum=0;
        long long min=1000000000;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)//输入数据
        {
            scanf("%lld",&a[i].num);
            a[i].id=i;
            if (a[i].num<min) min=a[i].num;
            sum+=a[i].num;
        }
        sum-=(min-1)*n;
        sort(a+1,a+n+1,cmp);
        a[0].num=a[1].num;//保证最左边数据的结果不变
        for (long long i=1;i<=n;i++)
        {
            sum=sum+(a[i].num-a[i-1].num)*(2*i-n-2);
            b[a[i].id]=sum;
        }
        for (int i=1;i<n;i++)
        {
            printf("%lld ",b[i]);
        }
        printf("%lld\n",b[n]);
    }
    return 0;
}