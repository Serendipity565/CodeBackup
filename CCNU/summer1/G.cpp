#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
ll b[510] = {0};
void solve()
{
    ll t;
    cin >> t;
    if (t == 2)
    {
        cout << "0.00000" << endl;
    }
    if (t >= 60)
    {
        cout << "0.61803" << endl;
    }
    else
    {
        double q = b[t - 1] * 1.0 / b[t];
        cout << fixed << setprecision(5) << q << endl;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    b[2] = 1;
    b[3] = 1;
    cin >> n;
    for (int i = 4; i <= 505; i++)
    {
        b[i] = b[i - 1] + b[i - 2];
    }

    while (n--)
    {
        solve();
    }
    /*
    for (int i = 60; i <= 90; i++)
    {
        cout << b[i] << " ";
    }
    for (int i = 60; i <= 90; i++)
    {
        double q = b[i - 1] * 1.0 / b[i];
        cout << fixed << setprecision(5) << q << endl;
    }
    */
    return 0;
}