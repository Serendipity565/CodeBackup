#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int64_t k;
int64_t n;

int64_t erfen(int64_t n, int64_t l, int64_t r)
{
    int64_t p = 1;
    while (l <= r)
    {
        int64_t mid = (l + r) / 2;
        int64_t sum = (k + mid) * (k - mid + 1) / 2 - (k - mid);
        if (sum == n)
        {
            return mid;
        }
        if (sum > n)
        {
            p = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return p;
}

void debug()
{
    return;
}

void solve()
{
    cin >> n >> k;
    if ((2 + k) * (k - 2 + 1) / 2 - (k - 2) < n)
    {
        cout << -1 << endl;
        return;
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (k == n)
    {
        cout << 1 << endl;
        return;
    }
    cout << k - erfen(n, 2, k) + 1 << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
