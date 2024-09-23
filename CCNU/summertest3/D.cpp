#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int a[300005] = {0};
int b[300005] = {0};

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    int mymin = n + 1;
    int mymini = n + 1;
    while (n--)
    {
        int x;
        cin >> x;
        if (mymin < x && x < mymini)
        {
            ans += 1;
            mymini = x;
        }
        mymin = min(mymin, x);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}