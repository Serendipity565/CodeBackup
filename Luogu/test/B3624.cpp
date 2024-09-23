#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n, l, r;
int w[105] = {0};
int cnt = 0;
void dfs(int sum, int now)
{
    if (sum > r)
    {
        return;
    }
    if (sum >= l && sum <= r)
    {
        cnt++;
    }
    for (int i = now + 1; i <= n; i++)
    {
        dfs(sum + w[i], i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(w[i], i);
    }
    cout << cnt << endl;
    return 0;
}