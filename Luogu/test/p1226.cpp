#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long res=1;
    long long a,b,p;
    scanf("%lld %lld %lld",&a,&b,&p);
    printf("%lld^%lld mod %lld=",a,b,p);
    while (b)
    {
        if (b%2==1)
        {
            res*=a;
            res%=p;
        }
        a=(a*a)%p;
        b/=2;
    }

    printf("%lld",res);
    return 0;
}