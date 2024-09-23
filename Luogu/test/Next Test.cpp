#include <bits/stdc++.h>
using namespace std;
int a[3009] = {0};
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i] != i)
        {
            cout << i << endl;
            return 0;
        }
    }
}