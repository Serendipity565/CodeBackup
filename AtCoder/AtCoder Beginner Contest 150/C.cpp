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
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        c[i] = i + 1;
    }
    int cnt = 1;
    bool flag1 = true;
    bool flag2 = true;
    int numa = 0;
    int numb = 0;
    do
    {
        flag1 = true;
        flag2 = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != c[i])
            {
                flag1 = false;
                break;
            }
        }
        if (flag1)
        {
            numa = cnt;
            // cout << numa << endl;
        }
        for (int i = 0; i < n; i++)
        {
            if (b[i] != c[i])
            {
                flag2 = false;
                break;
            }
        }
        if (flag2)
        {
            numb = cnt;
        }
        cnt++;
    } while (next_permutation(c.begin(), c.end()));
    cout << abs(numb - numa) << endl;
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