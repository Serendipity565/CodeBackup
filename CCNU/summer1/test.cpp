#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k, a, b, sum = 0;
    cin >> n >> k >> a >> b;
    if (k == 0)
    {
        sum = (n - 1) * a;
        n = 1;
    }
    while (n > 1)
    {
        if (n % k == 0)
        {
            if ((n - (n / k)) * a > b)
            {
                sum += b;
                n = n / k;
            }
            else
            {
                sum += (n - (n / k)) * a;
                n = n / k;
            }
        }
        else
        {
            sum += a;
            n--;
        }
    }
    cout << sum << '\n';
    return 0;
}