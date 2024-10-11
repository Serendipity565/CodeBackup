#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

struct B
{
    string name;
    int zu;
    int socre;
} a[1000006];
bool cmp(B a1, B a2)
{
    if (a1.zu == a2.zu)
    {
        return a1.socre > a2.socre;
    }
    return a1.zu < a2.zu;
}

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
        cin >> a[i].name >> a[i].zu >> a[i].socre;
    }
    sort(a + 1, a + 1 + n, cmp);
    int k = 0;
    int first;
    int second;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].zu != k)
        {
            k = a[i].zu;
            first = 0;
            second = 0;
        }
        else
        {
            continue;
        }

        if ((i + 1) <= n && (i + 2) <= n && a[i].zu == a[i + 1].zu && a[i + 2].zu == a[i + 1].zu && a[i + 2].socre == a[i + 1].socre)
        {
            cout << '?' << endl;
        }
        else
        {
            cout << a[i].name << " " << a[i + 1].name << endl;
        }
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