#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int n;
int tr[500005] = {0};
struct P
{
    int num;
    int id;
} a[500005];

bool cmp(P a1, P a2)
{
    if (a1.num == a2.num)
    {
        return a1.id > a2.id;
    }
    return a1.num > a2.num;
}

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int k)
{
    while (x <= n)
    {
        tr[x] += k;
        x += lowbit(x);
    }
}

int getsum(int x)
{
    int tot = 0;
    while (x > 0)
    {
        tot += tr[x];
        x -= lowbit(x);
    }
    return tot;
}

void solve()
{
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].num; // 当前数字
        a[i].id = i;     // 数字对应的下标
    }
    // 实现降序排列，数值大的在前面
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        update(a[i].id, 1);
        // 对于这个数而言，比他大的数都已经在数组内，只需查询下表比他小的即可
        ans += getsum(a[i].id - 1);
    }
    cout << ans;
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