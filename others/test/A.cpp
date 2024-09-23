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

int vis[50005] = {0};

void solve()
{
    int n;
    cin >> n;
    vector<int> prime;
    int num = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            num++;
        }
        for (int j = 1; j <= num && i * prime[j - 1] <= n; ++j)
        {
            vis[i * prime[j - 1]] = 1;
            if (i % prime[j - 1] == 0)
            {
                break;
            }
        }
    }
    cout << num << endl;
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