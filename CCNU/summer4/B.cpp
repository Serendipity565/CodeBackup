#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int a[100005] = {0};

void debug()
{

    return;
}

void solve()
{
    int n;
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i += 1)
    {
        a[i] = i;
    }
    if (n == 1)
    {
        cout << a[1] << endl;
        return;
    }
    reverse(a + n + 1 - k, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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