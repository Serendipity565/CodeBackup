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

int cj(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

void solve()
{
    int ax, ay;
    int bx, by;
    int cx, cy;
    int dx, dy;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    cin >> dx >> dy;

    double midx, midy;
    midx = (ax + cx) / 2.0;
    midy = (ay + cy) / 2.0;
    // cout << midx << " " << midy << endl;
    if ((cj(ax, ay, bx, by, cx, cy) > 0 && cj(bx, by, cx, cy, dx, dy) > 0 && cj(cx, cy, dx, dy, ax, ay) > 0 && cj(dx, dy, ax, ay, bx, by) > 0) ||
        (cj(ax, ay, bx, by, cx, cy) < 0 && cj(bx, by, cx, cy, dx, dy) < 0 && cj(cx, cy, dx, dy, ax, ay) < 0 && cj(dx, dy, ax, ay, bx, by) < 0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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