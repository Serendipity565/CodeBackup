#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{
    return;
}

bool cmp(int a, int b)
{
    return a > b;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 0; i <= n; ++i)
    {
        vector<int> b(a.begin(), a.begin() + i);
        sort(b.begin(), b.end(), cmp);

        int sum = 0;
        for (int j = 0; j < b.size(); j += 2)
        {
            sum += b[j];
        }
        if (sum <= k)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }

    cout << ans << endl;

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
