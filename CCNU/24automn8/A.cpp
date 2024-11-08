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
    int i, n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    vector<int> ma(26, 0), mb(26, 0);
    for (auto c : a)
    {
        ma[c - 'a']++;
    }
    for (auto c : b)
    {
        mb[c - 'a']++;
    }

    bool flag = false;
    for (i = 0; i < 26; i++)
    {
        if (ma[i] < mb[i] || (ma[i] -= mb[i]) % k)
        {
            flag = true;
        }
        if (i < 25)
        {
            ma[i + 1] += ma[i];
        }
    }

    cout << (flag ? "No" : "Yes") << endl;
    return;
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