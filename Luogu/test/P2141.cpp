#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
int a[105] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll cnt = 0;
    /*
    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
    */
    for (auto x : mp)
    {
        for (int i = 1; i + i < x.first; i++)
        {
            if (mp[i] > 0 && mp[x.first - i] > 0)
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}