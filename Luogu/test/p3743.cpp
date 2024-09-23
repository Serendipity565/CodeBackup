#include<bits/stdc++.h>
using namespace std;
double a[100005]={0};
double b[100005]={0};
double panduan(double mid,int n)
{
    double sum=0;
    for (int i=1;i<=n;i++)
    {
        if (b[i]/a[i]<mid)
        {
            sum+=(mid-(b[i]/a[i]))*a[i];
        }
    }
    return sum;
}
int main()
{
    int n;
    double p;
    double sum=0;
    scanf("%d %lf",&n,&p);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf %lf",&a[i],&b[i]);
        sum+=a[i];
    }
    if (p>=sum)
    {
        printf("-1");
        return 0;
    }
    else
    {
        double l=0,r=1e10;
        double res;
        while (l<=r && r-l>0.000001)
        {
            double mid=(l+r)/2.0;
            if (panduan(mid,n)<=p*mid)
            {
                res=mid;
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        printf("%lf",res);
        return 0;
    }
}