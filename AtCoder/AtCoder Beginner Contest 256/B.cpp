#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int a[1000] = {0};

void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;

    int p = 0;
    int f[] = {0, 0, 0, 0};

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int nf[] = {0, 0, 0, 0};
        f[0] = 1;
        for (int j = 0; j <= 3; j++)
        {
            if (f[j] == 1)
            {
                if (a[i] + j >= 4)
                {
                    p++;
                }
                else
                {
                    nf[a[i] + j] = 1;
                }
            }
        }
        for (int j = 0; j <= 3; j++)
        {
            f[j] = nf[j];
        }
    }
    cout << p << endl;
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