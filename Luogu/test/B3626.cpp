#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int a[1000006] = {0};
struct nod
{
    int num;
    int pla;
};

void solve()
{
    int n;
    cin >> n;
    queue<nod> q;
    nod no = {1, 0};
    q.push(no);
    while (!q.empty())
    {
        no = q.front();
        q.pop();

        if (no.num - 1 >= 1 && a[no.num - 1] == 0)
        {
            q.push({no.num - 1, no.pla + 1});
            a[no.num - 1] = 1;
        }

        if (no.num + 1 < n && a[no.num + 1] == 0)
        {
            q.push({no.num + 1, no.pla + 1});
            a[no.num + 1] = 1;
        }
        else if ((no.num + 1) == n)
        {
            cout << no.pla + 1 << endl;
            return;
        }
        if (no.num * 2 < n && a[no.num * 2] == 0)
        {
            q.push({no.num * 2, no.pla + 1});
            a[no.num * 2] = 1;
        }
        else if ((no.num * 2) == n)
        {
            cout << no.pla + 1 << endl;
            return;
        }
    }
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