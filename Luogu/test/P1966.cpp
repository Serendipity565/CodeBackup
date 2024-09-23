#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int Q = 1e8 - 3;

struct P
{
    int num;
    int id;
} a[100005], b[100005];

int res[100005] = {0};
int temp[100005] = {0};
ll sum = 0;

bool cmp(P a1, P a2)
{
    return a1.num < a2.num;
}

void debug()
{
    for (int i = 1; i <= 5; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return;
}

void msort(int l, int r)
{
    if (l < r) // 划分
    {
        int mid = (l + r) / 2;
        msort(l, mid);
        msort(mid + 1, r);

        // 开始合并
        int l1 = l, r1 = mid + 1;
        int k = l;
        while (l1 <= mid && r1 <= r)
        {
            if (res[l1] <= res[r1])
            {
                temp[k] = res[l1];
                k++;
                l1++;
            }
            else
            {
                temp[k] = res[r1];
                k++;
                r1++;
                sum = sum + mid - l1 + 1;
                sum %= Q;
            }
        }

        // 合并多余元素
        while (l1 <= mid)
        {
            temp[k] = res[l1];
            k++;
            l1++;
        }
        while (r1 <= r)
        {
            temp[k] = res[r1];
            k++;
            r1++;
        }

        // 储存临时数组
        for (int i = l; i <= r; i++)
        {
            res[i] = temp[i];
        }
        return;
    }
    else
        return;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].num;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].num;
        b[i].id = i;
    }
    sort(b + 1, b + 1 + n, cmp);

    for (int i = 1; i <= n; i++)
    {
        res[a[i].id] = b[i].id;
    }

    // debug();
    msort(1, n);
    cout << sum % Q << endl;
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