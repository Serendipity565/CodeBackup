#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[20000530]={0};
ll fast_pow(ll a,ll b,ll c)
{
	ll ans=1;
	a%=c;
	while (b)
	{
		if (b%2==1)
		{
			ans=(ans*a)%c;
		}
		a=(a*a)%c;
		b/=2;
	}
	return ans;
}
int main()
{
    ll n,p;
    scanf("%lld %lld",&n,&p);
	a[1]=fast_pow(1,p-2,p);
	printf("%lld\n",a[1]);
    for (ll i=2;i<=n;i++)
    {
		a[i]=(p-p/i)*a[p%i]%p;
        printf("%lld\n",a[i]);
    }
    return 0;
}