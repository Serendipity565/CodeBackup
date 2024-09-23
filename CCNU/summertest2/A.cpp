#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct nod
{
    int num;
} no[400005];

void solve()
{
    int n;
    cin >> n;
    int temp;
    no[1].num = 0;
    for (int i = 1; i <= n; i++)
    {

        cin >> temp;
        no[2 * i].num = no[temp].num + 1;
        no[2 * i + 1].num = no[temp].num + 1;
    }
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        if (no[i].num != -1)
        {
            cout << no[i].num << endl;
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
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}