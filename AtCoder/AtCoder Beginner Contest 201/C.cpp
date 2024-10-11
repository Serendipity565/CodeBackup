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
    string s;
    cin >> s;
    int cnt1 = 0;
    map<int, int> mp;
    for (int i = 0; i <= 9; i++)
    {
        if (s[i] == 'o')
        {
            mp[i] = 1;
            cnt1++;
        }
        else if (s[i] == 'x')
        {
            mp[i] = 0;
        }
        else
        {
            mp[i] = 2;
        }
    }
    if (cnt1 > 4)
    {
        cout << 0 << endl;
        return;
    }
    int sum = 0;
    for (int i = 0; i <= 9999; i++)
    {
        bool flag = true;
        int temp = i;
        set<int> se;
        for (int j = 1; j <= 4; j++)
        {
            if (mp[temp % 10])
            {
                if (mp[temp % 10] == 1)
                {
                    se.insert(temp % 10);
                }
            }
            else
            {
                flag = false;
                break;
            }
            temp /= 10;
        }
        if (flag && se.size() == cnt1)
        {
            sum++;
        }
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