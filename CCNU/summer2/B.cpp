#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct B
{
    ll l;
    ll r;
} lq[200005];

ll li[200005] = {0};

bool cmp(B a1, B a2)
{
    return a1.r < a2.r;
}

void solve()
{
    ll n;
    ll m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> lq[i].l >> lq[i].r;
        li[i] = lq[i].l;
    }
    sort(lq + 1, lq + 1 + n, cmp);
    sort(li + 1, li + 1 + n);
    map<ll, ll> mp;
    int j = 1;
    ll mymax = 0;
    for (int i = 1; i <= n; i++)
    {
        while (j <= n && li[j] <= lq[i].r)
        {
            mp[li[j]]++;
            j++;
        }
        int cny = 0;
        for (auto x : mp)
        {
            cny += x.second;
            if (cny >= 2)
            {
                mymax = max(mymax, lq[i].r - x.first + 1);
                mp[lq[i].l]--;
                if (mp[lq[i].l] == 0)
                {
                    mp.erase(lq[i].l);
                }
                break;
            }
        }
        if (cny < 2)
        {
            mp[lq[i].l]--;
            if (mp[lq[i].l] == 0)
            {
                mp.erase(lq[i].l);
            }
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
    // t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}