#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
ll a[100005] = {0};

void solve()
{
    int n;
    cin >> n;
    map<ll, int> m;
    int mymax = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
        if (m[a[i]] > mymax)
        {
            mymax = m[a[i]];
        }
    }
    if (n == 1 || mymax == n)
    {
        cout << 0 << endl;
        return;
    }
    n -= mymax;
    int k = 1;
    int temp = mymax;
    while (n > 0)
    {
        if (mymax >= 1)
        {
            n -= 1;
            mymax -= 1;
            k += 1;
        }
        else
        {
            temp *= 2;
            mymax = temp;
            k++;
        }
    }
    cout << k << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}