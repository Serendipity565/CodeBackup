#include<bits/stdc++.h>
using namespace std;
double panduan(double mid,int w0,int w,int m)
{
    double res=w0;
    for (int i=1;i<=m;i++)
    {
        res=res*mid-w;
    }
    return res;
}
int main()
{
    int w0,w,m;
    scanf("%d %d %d",&w0,&w,&m);
    double l=0,r=5;
    double mid=(l+r)/2;
    while (abs(panduan(mid,w0,w,m))>0.0001 && r-l>0.000001)
    {
        if (panduan(mid,w0,w,m)>0)
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
        mid=(l+r)/2;
    }
    mid-=1;
    mid*=100;
    printf("%.1f",mid);
    return 0;
}