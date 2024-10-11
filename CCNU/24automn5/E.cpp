#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int a[200005] = {0};
int b[200005] = {0};

void debug()
{
    return;
}

void solve()
{
    int n;
    int op;
    int ai, xi;
    int ki;
    int j = 0;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> ai >> xi;
            b[i]
        }
        else if (op == 2)
        {
            cin >> ki;
            j++;
            sum += ki;
            a[j] = ki;
        }
        else
        {
            sum -= a[j];
            j--;
        }
        cout << fixed << setprecision(6) << sum / (j + 1) << endl;
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