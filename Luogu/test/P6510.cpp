#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll h[100005] = {0};
ll l[100005] = {0};
ll r[100005] = {0};

void debug()
{
    for (int i = 1; i <= 5; i++)
    {
        cout << l[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= 5; i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;
    return;
}

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    stack<ll> st;
    for (ll i = 1; i <= n; i++) // 寻找左边第一个大于等于A的
    {
        while (!st.empty() && h[st.top()] < h[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            l[i] = st.top();
        }
        else
        {
            l[i] = 0;
        }
        st.push(i);
    }
    stack<ll> st1;
    for (ll i = n; i >= 1; i--) // 寻找右边第一个小于等于B的
    {
        while (!st1.empty() && h[st1.top()] > h[i])
        {
            st1.pop();
        }
        if (!st1.empty())
        {
            r[i] = st1.top();
        }
        else
        {
            r[i] = n + 1;
        }
        st1.push(i);
    }
    // debug();
    ll ans = 0;
    for (ll i = n; i >= 1; i--)
    {
        for (ll j = l[i] + 1; j < i; j++)
        {
            if (r[j] > i)
            {
                ans = max(ans, i - j + 1);
                break;
            }
        }
    }
    cout << ans << endl;
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