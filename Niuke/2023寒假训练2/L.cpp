#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        double c,d,h,w;
        double sum=0;
        scanf(" %lf %lf %lf %lf",&c,&d,&h,&w);
        double sum1=3*w*c;
        printf("%lf\n",sum1);
        t--;
    }
    return 0;
}