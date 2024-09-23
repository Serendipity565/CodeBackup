#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int dp[1005][1005] = {0};

void solve()
{
    string s1;
    cin >> s1;
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << s1.size() - dp[s1.size()][s1.size()] << endl;
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