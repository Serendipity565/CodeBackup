#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[1000006] = {0};
ll q[1000006] = {0};

void debug()
{

    return;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int head = 1;
    int tail = 0;
    for (int i = 1; i < m; i++)
    {
        while (head <= tail && a[q[tail]] >= a[i])
        {
            tail--;
        }
        tail++;
        q[tail] = i;
    }
    for (int i = m; i <= n; i++)
    {
        while (head <= tail && a[q[tail]] >= a[i])
        {
            tail--;
        }
        tail++;
        q[tail] = i;
        while (q[head] <= i - m)
        {
            head++;
        }
        cout << a[q[head]] << endl;
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