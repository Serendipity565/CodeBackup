#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll a[100004] = {0};

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
    int mymax = 1;
    int temp = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1] + 1)
        {
            temp++;
            mymax = max(mymax, temp);
        }
        else
        {
            temp = 1;
        }
    }
    cout << mymax << endl;
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