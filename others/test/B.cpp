#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void debug()
{
    return;
}

void solve()
{
    int n, l;
    cin >> n >> l;
    int d, r, g;
    int time = 0;
    int tempd = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> d >> r >> g;
        time += d - tempd;
        int temp = time % (g + r);
        if (temp < r)
        {
            time += r - temp;
        }
        tempd = d;
    }
    time += l - tempd;
    cout << time << endl;

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