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
    string s;
    cin >> n;
    cin >> s;
    if (n % 2 == 0)
    {
        map<char, int> mp1;
        int mymax1 = 0;
        for (int i = 0; i < n; i += 2)
        {
            mp1[s[i]]++;
            if (mp1[s[i]] > mymax1)
            {
                mymax1 = mp1[s[i]];
            }
        }

        map<char, int> mp2;
        int mymax2 = 0;
        for (int i = 1; i < n; i += 2)
        {
            mp2[s[i]]++;
            if (mp2[s[i]] > mymax2)
            {
                mymax2 = mp2[s[i]];
            }
        }
        cout << n - mymax1 - mymax2 << endl;
    }
    else
    {
        int res = n;
        vector<vector<int>> pre(2, vector<int>(26));
        vector<vector<int>> nie(2, vector<int>(26));
        for (int i = n - 1; i >= 0; i--)
        {
            nie[i % 2][s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            nie[i % 2][s[i] - 'a']--;
            int ans = n;
            for (int k = 0; k < 2; k++)
            {
                int mymax = 0;
                for (int j = 0; j < 26; j++)
                {
                    mymax = max(mymax, nie[1 - k][j] + pre[k][j]);
                }
                ans -= mymax;
            }
            res = min(res, ans);
            pre[i % 2][s[i] - 'a']++;
        }
        cout << res << endl;

        return;
    }
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