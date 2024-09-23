#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
int v[100005] = {0};
void solve()
{
    int n;
    cin >> n;
    ll cnt = 1;
    ll mymax = INT64_MIN;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum += v[i];
        // cout << sum << endl;
        if (sum > mymax)
        {
            mymax = sum;
            cnt = 1;
        }
        else if (sum == mymax)
        {
            cnt++;
        }
    }
    cout << mymax << " " << cnt;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}