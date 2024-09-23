#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int c[500005] = {0};
int a[500005] = {0};

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    k = max(2, k);
    ll sum = 0;
    int l = 1, r = l;
    while (l <= n)
    {
        r = max(l, r);

        while (c[r + 1] != c[r] && r < n)
        {
            r++;
            if (r - l + 1 >= k)
            {
                a[c[r]]++;
            }
        }
        if (r - l + 1 >= k)
        {
            sum = sum + r - l + 1 - k + 1 - a[c[l]];
            a[c[l + k - 1]]--;
        }
        l++;
    }
    cout << sum << endl;
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