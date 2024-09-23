#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll a[200005] = {0};

void debug()
{
    return;
}

void solve()
{
    int h;
    cin >> h;
    h++;
    bool flag = true;
    for (int i = 1; i <= h; i++)
    {
        cin >> a[i];
        if (a[i] > 1 && a[i - 1] > 1)
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << "perfect" << endl;
        return;
    }
    else
    {
        cout << "ambiguous" << endl;
    }
    int k = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            cout << k << " ";
        }
        k += a[i];
    }
    cout << endl;
    k = 0;
    for (int i = 1; i <= h; i++)
    {
        if (a[i - 1] >= 2 && (!flag))
        {
            for (int j = 1; j < a[i]; j++)
            {
                cout << k << " ";
            }
            cout << k - 1 << " ";
        }
        else
        {
            for (int j = 1; j <= a[i]; j++)
            {
                cout << k << " ";
            }
        }

        k += a[i];
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