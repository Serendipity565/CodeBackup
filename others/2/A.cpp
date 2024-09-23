#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

vector<bitset<32>> a(1000006);
int d[1000006] = {0};

void debug()
{

    return;
}

void solve()
{
    int n;
    cin >> n;
    ll temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a[i] = bitset<32>(temp);
    }
    for (int j = 31; j >= 0; j--)
    {
        int cnt = 0;
        vector<int> id;
        for (int i = 1; i <= n; i++)
        {
            if (d[i] == 0)
            {
                if (a[i][j] == 1)
                {
                    cnt++;
                }
                else
                {
                    id.push_back(i);
                }
            }
        }
        if (cnt >= 2)
        {
            for (auto x : id)
            {
                d[x] = 1;
            }
        }
    }
    int q = 1;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            if (q == 1)
            {
                cout << i << " ";
                q++;
            }
            else
            {
                cout << i << endl;
                return;
            }
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