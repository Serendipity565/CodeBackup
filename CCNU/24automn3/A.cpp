#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int n;
int a[500];
void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    if (a[0] == a[n - 1])
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << a[n - 1] << " ";
        for (int i = 0; i < n - 1; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
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