#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll ans[100005] = {0};
ll cnt[100005] = {0};

void solve()
{
    ll n;
    ll m;
    cin >> n >> m;
    vector<ll> ve[n + 1];
    ll a, b;
    for (ll i = 1; i <= m; i++)
    {
        cin >> a >> b;
        cnt[b]++;
        ve[a].push_back(b);
    }
    ll mymax = 0;
    queue<ll> q;
    for (ll i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        ll temp = q.front();
        q.pop();
        for (int i : ve[temp])
        {
            cnt[i]--; // 入度
            if (cnt[i] == 0)
            {
                q.push(i);
            }
            ans[i] = max(ans[i], ans[temp] + 1);
            mymax = max(mymax, ans[i]);
            /*
            if (ans[temp] + 1 > ans[i])
            {
                ans[i] = ans[temp] + 1;
                q.push(i);
                mymax = ans[i];
            }
            */
        }
    }
    cout << mymax << endl;
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