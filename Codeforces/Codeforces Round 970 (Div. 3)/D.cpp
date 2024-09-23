#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int a[200005] = {0};
int fa[200005] = {0};

int find(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    else
    {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

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
        fa[i] = i;
        a[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int nex;
        cin >> nex;
        int fi = find(i);
        int fj = find(nex);
        if (fi != fj)
        {
            fa[i] = fj;
        }
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '0')
        {
            a[find(i)]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[find(i)] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}