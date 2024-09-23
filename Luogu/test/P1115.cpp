#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
ll a[200005] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll mymin = 0;
    ll sum = INT64_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {

        if (a[i - 1] < a[mymin])
        {
            mymin = i - 1;
        }
        if (a[i] - a[mymin] > sum)
        {
            sum = a[i] - a[mymin];
        }
    }

    cout << sum << endl;
    return 0;
}