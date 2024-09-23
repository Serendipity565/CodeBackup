#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < b.size(); i++)
    {
        int cnt = 0;
        int temp = i;
        for (int j = 0; j < a.size(); j++)
        {
            if (b[temp] == a[j] && temp < b.size())
            {
                temp++;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << a.size() + b.size() - ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}
