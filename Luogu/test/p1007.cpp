#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a[5003] = {0};
    int l, n;
    cin >> l;
    cin >> n;
    int mymin = 0;
    int mymax = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mymin = max(min(l + 1 - a[i], a[i]), mymin);
        mymax = max(max(l + 1 - a[i], a[i]), mymax);
    }
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i] - a[i + 1]) % 2 == 0)
        {
            mymax = max(max((l + 1 - (a[i + 1] + a[i]) / 2), (a[i] + a[i + 1]) / 2) + abs((a[i + 1] - a[i]) / 2), mymax);
        }
        else
        {
            mymax = max(max(l - (a[i + 1] + a[i]) / 2, (a[i + 1] + a[i]) / 2) + abs((a[i + 1] - a[i]) / 2), mymax);
        }
    }
    cout << mymin << " " << mymax;
    return 0;
}