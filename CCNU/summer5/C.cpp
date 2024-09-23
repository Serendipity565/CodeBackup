#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int dp1[1000006] = {0};
int dp2[1000006] = {0};
void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = n - 1; i >= 0; i--)
    {
        dp1[i] = dp2[i + 1];
        if (s[i] == '1')
        {
            dp1[i]++;
        }
        if (i + 1 < n)
        {
            int ans1 = dp1[i];
            int ans2 = dp2[i + 2];
            if (s[i] == '1')
            {
                ans2++;
            }
            if (s[i + 1] == '1')
            {
                ans2++;
            }
            dp1[i] = min(ans1, ans2);
        }
        dp2[i] = dp1[i + 1];
        if (i + 1 < n)
        {
            dp2[i] = min(dp2[i], dp1[i + 2]);
        }
    }
    cout << dp1[0] << endl;
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