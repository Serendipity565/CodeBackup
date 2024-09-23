#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, n, k;
    cin >> n >> k >> a >> b;
    ll sum = 0;
    while (n > 1)
    {
        if (n % k == 0 && (n - n / k) * a >= b)
        {
            n /= k;
            sum += b;
        }
        else if (n > k)
        {
            sum += (n - ((n / k) * k)) * a;
            n = (n / k) * k;
        }
        else if (n == k)
        {
            if (b > a * (n - 1))
            {
                sum += a * (n - 1);
            }
            else
            {
                sum += b;
            }
            n = 1;
        }
        else if (n < k)
        {
            sum += (n - 1) * a;
            n = 1;
        }
        // cout << n << endl;
        if (n % k == 0 && (n - n / k) * a < b && n > k)
        {
            sum += (n - 1) * a;
            n = 1;
        }
    }
    cout << sum << endl;
    return 0;
}