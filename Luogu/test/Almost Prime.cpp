#include <bits/stdc++.h>
using namespace std;
bool is(int k)
{
    for (int i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            return false;
        }
    }
    return true;
}
bool check(int k)
{
    int cnt = 0;
    for (int i = 2; i <= k; i++)
    {
        if (k % i == 0 && is(i))
        {
            cnt++;
        }
    }
    if (cnt == 2)
    {
        return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    int ans = 0;
    for (int i = 1; i <= t; i++)
    {
        if (check(i))
        {

            ans++;
        }
    }
    cout << ans;
    return 0;
}