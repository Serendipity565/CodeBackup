#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e15 + 7;

ll fast_pow(ll a, ll b, ll c)
{
    ll ans = 1;
    a %= c;
    while (b) // 不能写成b>1，否则会出问题！！！
    {
        if (b % 2 == 1) // 可以用b&1进行更快的判断
        {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b /= 2; // 可以用b>>=1来代替
    }
    return ans;
}
void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    cout << fast_pow(2, n, mod) << endl;
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