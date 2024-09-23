#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const ll mymod=998244353;
int main()
{
	int t;
	scanf("%d",&t);
	while(t)
	{
    	ll n,m;
    	scanf("%lld %lld",&n,&m);
		n--;m--;
    	printf("%d\n",fast_pow(2,n*m,mymod));
		t--;
	}
	return 0;
}