#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int a[2003] = {0};

void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    int temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a[temp] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        if (a[i] == 0)
        {
            cout << i << endl;
            return;
        }
    }
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