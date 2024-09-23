#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int a[1000006] = {0};
int b[] = {};

void debug()
{

    return;
}

void solve()
{
    int n;
    cin >> n;
    int temp;
    int mymax = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        mymax = max(mymax, temp);
        a[temp]++;
    }

    int cnt = 0;
    for (int i = 2; i <= mymax; i++)
    {
        int ans = 0;
        int k = 1;
        while (i * k <= mymax)
        {
            ans += a[i * k];
            k++;
        }
        cnt = max(cnt, ans);
    }
    cout << cnt << endl;
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