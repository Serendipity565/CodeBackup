#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
ll a[105] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 0)
    {
        cout << "Bob";
    }
    else
    {
        cout << "Alice";
    }
    return 0;
}