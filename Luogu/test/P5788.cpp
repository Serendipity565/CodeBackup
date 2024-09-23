#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[3000006] = {0};
ll f[3000006] = {0};

void debug()
{

    return;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[n] = 0;
    stack<ll> st;
    st.push(n);
    for (int i = n - 1; i >= 1; i--)
    {
        while (!st.empty() && a[st.top()] <= a[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            f[i] = st.top();
        }
        else
        {
            f[i] = 0;
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << f[i] << " ";
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