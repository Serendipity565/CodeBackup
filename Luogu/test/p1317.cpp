#include <bits/stdc++.h>
using namespace std;
int p[10004] = {0};
bool check(int a, int b, int c)
{
    if (a >= b && b < c)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        if (check(p[i], p[i + 1], p[i + 2]))
        {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
