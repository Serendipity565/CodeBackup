#include <bits/stdc++.h>
using namespace std;
bool d[2000006];

int main()
{
    int n;
    cin >> n;
    double a;
    int t;
    while (n--)
    {
        cin >> a >> t;
        for (int i = 1; i <= t; i++)
        {
            d[(int)(i * a)] = (d[(int)(i * a)] + 1) % 2;
        }
    }
    for (int i = 1;; i++)
    {
        if (d[i] == 1)
        {
            cout << i << endl;
            return 0;
        }
    }
}