#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{
    return;
}

int n, a[30] = {0};

void solve()
{
    int n;
    cin >> n;
    a[0] = 1, a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            a[i] += a[j] * a[i - j - 1];
        }
    }
    cout << a[n] << endl;
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