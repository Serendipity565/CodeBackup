#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int t[1005] = {0};
int q[1005] = {0};

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    map<int, int> ans;
    for (int j = 1; j <= n; j++)
    {
        int i = j;
        map<int, int> mp;
        mp[i] = 1;
        while (q[i] == 0)
        {
            if (t[i] == 0)
            {
                ans[i] = 1;
                for (auto x : mp)
                {
                    int temp = x.first;
                    ans[temp] = 1;
                }
                        }
            q[i] = 1;
            mp[i] = 1;
            i = t[i];
        }
        mp[i] = 1;
        if (ans[i] == 1)
        {
            for (auto x : mp)
            {
                int temp = x.first;
                ans[temp] = 1;
            }
        }
    }
    int sum = 0;
    for (auto x : ans)
    {
        if (x.second == 1)
        {
            // cout << x.first << " " << x.second << endl;
            sum ^= x.first;
        }
    }
    cout << sum << endl;
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