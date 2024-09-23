#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<set<int>> v(n + 1);
    int temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        v[i].insert(temp);
    }
    int a, b;
    for (int i = 1; i <= q; i++)
    {
        cin >> a >> b;
        if (v[a].size() <= v[b].size())
        {
            for (auto x : v[a])
            {
                v[b].insert(x);
            }
            v[a].clear();
            cout << v[b].size() << endl;
        }
        else
        {
            for (auto x : v[b])
            {
                v[a].insert(x);
            }
            v[b].clear();
            swap(v[a], v[b]);
            cout << v[b].size() << endl;
        }
    }

    return 0;
}