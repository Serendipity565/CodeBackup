#include <stdio.h>

typedef long long ll;

ll fast_pow(ll a, ll b, ll c)
{
    ll ans = 1;
    a %= c;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b /= 2;
    }
    return ans;
}

int main()
{
    int a;
    ll b;
    scanf("%d %lld", &a, &b);

    ll result = fast_pow(a, b, 1000);
    printf("%03lld\n", result);

    return 0;
}
