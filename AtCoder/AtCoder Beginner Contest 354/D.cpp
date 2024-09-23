#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long sum = (d - b) * ((c - a) / 4) * 4;
    long long len1 = (c - a) % 4;
    int q = (a % 4 + 4) % 4; // 保证为正
    int ans[4][2] = {{2, 1}, {1, 2}, {0, 1}, {1, 0}};
    int cnt[4] = {3, 3, 1, 1};
    for (int i = 0; i < len1; i++)
    {
        sum += (d - b) / 2 * cnt[(q + i) % 4];
        if ((d - b) % 2 == 1)
        {
            sum += ans[(q + i) % 4][(b % 2 + 2) % 2];
        }
    }

    cout << sum;
    return 0;
}