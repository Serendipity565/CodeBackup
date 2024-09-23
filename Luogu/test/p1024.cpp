#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
bool hanshu(double x,double y)
{
    double res1=pow(x,3)*a+pow(x,2)*b+x*c+d;
    double res2=pow(y,3)*a+pow(y,2)*b+y*c+d;
    if (res1*res2<=0) return 1;
    else return 0;
}
double res(double x,double y)
{
    double mid;
    while (1)
    {
        mid=(x+y)/2;
        if (mid-x<=0.001) break;
        if (hanshu(x,mid)) y=mid;
        else x=mid;
    }
    return mid;
}
int main()
{
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    int w=3;
    double l=-101,r=l+1;
    while (w>0)
    {
        l+=1.001;r+=1.001;
        while (!hanshu(l,r))
        {
            l++;
            r++;
        }
        double l1=l,r1=r;
        printf("%0.2lf ",res(l1,r1));
        w--;
    }
    return 0;
}