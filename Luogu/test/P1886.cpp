#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int n, k;
ll a[1000005] = {0};
ll q[1000005] = {0};

void getmin()
{
    int head = 0, tail = -1;
    for (int i = 1; i < k; i++)
    {
        while (head <= tail && a[q[tail]] >= a[i])
        {
            tail--;
        }
        q[++tail] = i;
    }
    for (int i = k; i <= n; i++)
    {
        while (head <= tail && a[q[tail]] >= a[i])
        {
            tail--;
        }
        q[++tail] = i;
        while (q[head] <= i - k)
        {
            head++;
        }
        cout << a[q[head]] << " ";
    }
    return;
}

void getmax()
{
    int head = 0, tail = -1;
    for (int i = 1; i < k; i++)
    {
        while (head <= tail && a[q[tail]] <= a[i])
        {
            tail--;
        }
        q[++tail] = i;
    }
    for (int i = k; i <= n; i++)
    {
        while (head <= tail && a[q[tail]] <= a[i])
        {
            tail--;
        }
        q[++tail] = i;
        while (q[head] <= i - k)
        {
            head++;
        }
        cout << a[q[head]] << " ";
    }
    return;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    getmin();
    cout << endl;
    getmax();
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