#include <bits/stdc++.h>
using namespace std;
int a[10005] = {0};
int main()
{
    int l, m;
    cin >> l >> m;
    for (int i = 0; i <= l; i++)
    {
        a[i] = 1;
    }
    int u, v;
    while (m--)
    {
        cin >> u >> v;
        for (int i = u; i <= v; i++)
        {
            a[i] = 0;
        }
    }
    int sum = 0;
    for (int i = 0; i <= l; i++)
    {
        if (a[i] == 1)
        {
            sum++;
        }
    }
    cout << sum << endl;

    return 0;
}