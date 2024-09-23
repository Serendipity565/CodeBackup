#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string a(n, '0');
    int now = 0;
    int k = 0;
    int ans = 0;
    while (k < n)
    {
        if (now <= ans && k != 0)
        {
            a[k - 1] = '0';
        }
        a[k] = '1';
        k++;
        cout << "? " << a;
        cout << std::endl;
        ans = now;
        cin >> now;
    }
    if (now == ans)
    {
        a[n - 1] = '0';
    }
    cout << "! " << a;
    cout << std::endl;
    return;
}

int main()
{
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
