#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

void solve()
{
    int x, y;
    cin >> x >> y;
    if (x <= ceil(y * 0.1) || x > ceil(y * 0.6))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}