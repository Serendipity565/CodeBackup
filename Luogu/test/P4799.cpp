#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[45];
int k[45] = {0};

struct node
{
    ll sum;
    int i;
};

void solve()
{
    int n;
    ll m;
    cin >> n >> m;

    int n2 = n / 2;
    vector<ll> sum1;
    vector<ll> sum2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        if (a[1] <= m)
        {
            cout << 2 << endl;
            return;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    queue<node> q1;
    q1.push({a[1], 1});
    node sum;
    sum1.push_back(0);
    while (!q1.empty())
    {
        sum = q1.front();
        q1.pop();
        if (sum.sum <= m)
        {
            sum1.push_back(sum.sum);
        }
        for (int i = sum.i + 1; i <= n2; i++)
        {
            if (sum.sum + a[i] <= m)
            {
                q1.push({sum.sum + a[i], i});
            }
            if (a[i] <= m && k[i] == 0)
            {
                q1.push({a[i], i});
                k[i] = 1;
            }
        }
    }

    queue<node> q2;
    q2.push({a[n2 + 1], n2 + 1});
    sum2.push_back(0);
    while (!q2.empty())
    {
        sum = q2.front();
        q2.pop();
        if (sum.sum <= m)
        {
            sum2.push_back(sum.sum);
        }
        for (int i = sum.i + 1; i <= n; i++)
        {
            if (sum.sum + a[i] <= m)
            {
                q2.push({sum.sum + a[i], i});
            }
            if (a[i] <= m && k[i] == 0)
            {
                q2.push({a[i], i});
                k[i] = 1;
            }
        }
    }
    sort(sum2.begin(), sum2.end());
    /*
    for (int i = 0; i < sum1.size(); i++)
    {
        cout << sum1[i] << endl;
    }
    for (int i = 0; i < sum2.size(); i++)
    {
        cout << sum2[i] << endl;
    }
    */
    ll ans = 0;
    for (int i = 0; i < sum1.size(); i++)
    {
        auto t = upper_bound(sum2.begin(), sum2.end(), m - sum1[i]) - sum2.begin();
        ans += 1 * t;
        // cout << ans << endl;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}