#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    int pre = 0;
    int now;
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> now;

        cnt += pre - now;
        if (cnt < 0)
        {
            sum += -cnt;
            cnt = 0;
        }
        pre = now;
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
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}