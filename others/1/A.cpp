#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int a[] = {3, 1, 4, 1, 5, 9};
void solve()
{
    char q;
    char p;
    cin >> p >> q;
    int i = p - 'A';
    int j = q - 'A';
    int sum = 0;
    for (int k = min(i, j); k < max(i, j); k++)
    {
        sum += a[k];
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