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

ll res[50004] = {0};
ll temp[50004] = {0};
ll sum;

void msort(int l, int r) // l和r为待排序数组的左右边界
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
                sum = sum + mid - l1 + 1; // 此处计算逆序对
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
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> res[i];
    }
    sum = 0;
    msort(1, n);
    if (sum > (n * (n - 1) / 2 - 1))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}