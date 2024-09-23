#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n, m;
void debug()
{
    return;
}
int lowbit(int x)
{
    return x & (-x);
}
struct P
{
    int tr[2050][2050] = {0};
    void update(int x, int y, int k)
    {
        while (x <= n)
        {
            int a = y;
            while (a <= m)
            {
                tr[x][a] += k;
                a += lowbit(a);
            }
            x += lowbit(x);
        }
    }

    int getsum(int x, int y)
    {
        int ans = 0;
        while (x >= 1)
        {
            int a = y;
            while (a >= 1)
            {
                ans += tr[x][a];
                a -= lowbit(a);
            }
            x -= lowbit(x);
        }
        return ans;
    }
} my1, my2, my3, my4; // 分别维护tr[i][j],tr[i][j]*i,tr[i][j]*j,tr[i][j]*i*j;

void updateall(int x, int y, int k)
{
    my1.update(x, y, k);
    my2.update(x, y, k * x);
    my3.update(x, y, k * y);
    my4.update(x, y, k * x * y);
}

int getsumall(int x, int y)
{
    int ans = 0;
    ans += my1.getsum(x, y) * (x * y + x + y + 1);
    ans -= my2.getsum(x, y) * (y + 1);
    ans -= my3.getsum(x, y) * (x + 1);
    ans += my4.getsum(x, y);
    return ans;
}

void solve()
{
    char op;
    cin >> op >> n >> m;
    int a, b, c, d, k;
    while (cin >> op)
    {
        if (op == 'L')
        {
            cin >> a >> b >> c >> d >> k;
            updateall(a, b, k);
            updateall(a, d + 1, -k);
            updateall(c + 1, b, -k);
            updateall(c + 1, d + 1, k);
        }
        else if (op == 'k')
        {
            cin >> a >> b >> c >> d;
            cout << getsumall(c, d) - getsumall(a - 1, d) - getsumall(c, b - 1) + getsumall(a - 1, b - 1) << endl;
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