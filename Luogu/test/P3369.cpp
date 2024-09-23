#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    int op;
    int x;
    vector<int> a;
    while (n--)
    {
        cin >> op >> x;
        if (op == 1)
        {
            a.insert(lower_bound(a.begin(), a.end(), x), x);
        }
        else if (op == 2)
        {
            a.erase(lower_bound(a.begin(), a.end(), x));
        }
        else if (op == 3)
        {
            cout << lower_bound(a.begin(), a.end(), x) - a.begin() + 1 << endl;
        }
        else if (op == 4)
        {
            cout << a[x - 1] << endl;
        }
        else if (op == 5)
        {
            cout << a[lower_bound(a.begin(), a.end(), x) - a.begin() - 1] << endl;
        }
        else
        {
            cout << a[upper_bound(a.begin(), a.end(), x) - a.begin()] << endl;
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