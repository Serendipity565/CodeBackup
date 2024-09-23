#include <bits/stdc++.h>
using namespace std;
long long a[100005] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool flag = true;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long temp = __gcd(a[1], a[2]);
    if (temp > 1)
    {
        for (int i = 2; i < n; i++)
        {
            if (__gcd(a[i], a[i + 1]) != 1 && (__gcd(a[i], a[i + 1]) % temp == 0 || temp % __gcd(a[i], a[i + 1]) == 0))
            {
                temp = min(temp, __gcd(a[i], a[i + 1]));
                continue;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    cout << "YES" << "\n";
    if (flag && temp > 1)
    {
        cout << 0;
        return 0;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] % 2 == 1 && a[i + 1] % 2 == 1)
        {
            ans++;
            long long b = a[i];
            long long c = a[i + 1];
            a[i] = b - c;
            a[i + 1] = b + c;
        }
        else if (a[i] % 2 == 1 && a[i + 1] % 2 == 0)
        {
            ans += 2;
            long long b = a[i];
            long long c = a[i + 1];
            a[i] = -2 * c;
            a[i + 1] = 2 * b;
        }
    }
    if (a[n] % 2 == 1)
    {
        ans += 2;
    }
    cout << ans;
    return 0;
}