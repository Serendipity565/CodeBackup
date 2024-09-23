#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct Node
{
    double v;
    int id;
} n1[1005], n2[1005];

bool cmp(Node x, Node y)
{
    return x.v > y.v;
}

void solve()
{
    int k, n;
    cin >> n >> k;
    double c;
    int t;
    int l1 = 0, l2 = 0;
    double n1min = 0x3f3f3f3f;
    double n2min = 0x3f3f3f3f;
    double n1max = 0, n2max = 0, sum1 = 0, sum2 = 0;
    double sum = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> c >> t;
        if (t == 2)
        {
            n2[l2].id = i;
            n2[l2].v = c;
            l2++;
            n2min = min(n2min, c);
            n2max = max(n2max, c);
            sum2 += c;
        }
        else
        {
            n1[l1].id = i;
            n1[l1].v = c;
            l1++;
            n1min = min(n1min, c);
            n1max = max(n1max, c);
            sum1 += c;
        }
    }

    if (l1 >= k)
    {
        sort(n1, n1 + l1, cmp);
        for (int i = 0; i < k - 1; i++)
        {
            sum += n1[i].v;
        }
        sum *= 0.5;
        for (int i = k - 1; i < l1; i++)
        {
            sum += n1[i].v;
        }
        sum += sum2;
        sum -= min(n2min, n1min) * 0.5;
        cout << fixed << setprecision(1) << sum << endl;

        for (int i = 0; i < k - 1; i++)
        {
            cout << 1 << " " << n1[i].id << endl;
        }
        cout << l2 + l1 - k + 1;
        for (int i = k - 1; i < l1; i++)
        {
            cout << " " << n1[i].id;
        }
        for (int i = 0; i < l2; i++)
        {
            cout << " " << n2[i].id;
        }
        cout << endl;
    }
    else
    {
        sum1 *= 0.5;
        sum += sum1 + sum2;
        cout << fixed << setprecision(1) << sum << endl;

        for (int i = 0; i < l1; i++)
        {
            cout << 1 << " " << n1[i].id << endl;
        }
        for (int i = 0; i < k - l1 - 1; i++)
        {
            cout << 1 << " " << n2[i].id << endl;
        }
        cout << l2 - k + l1 + 1;
        for (int i = k - l1 - 1; i < l2; i++)
        {
            cout << " " << n2[i].id;
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
