#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int q = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i * (i + 1) >= 2 * n)
        {
            q = i;
            break;
        }
    }

    int p = n - (q - 1) * q / 2;

    if ((q + 1) % 2 == 1)
    {
        cout << p << "/" << (q + 1 - p);
    }
    else
    {
        cout << (q + 1 - p) << "/" << p;
    }

    return 0;
}