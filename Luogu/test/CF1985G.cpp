#include <bits/stdc++.h>
using namespace std;

long long fast_pow(long long a, long long b, long long c)
{
    long long ans = 1;
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
void solve()
{
    long long l, r, k;
    cin >> l >> r >> k;
    long long ans = 9 / k;
    long long cnt;
    long long c = 1e9 + 7;
    cnt = fast_pow(ans + 1, l, c);
    cnt *= (fast_pow(ans + 1, r - l, c) - 1);
    cnt %= c;

    cout << cnt << "\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
