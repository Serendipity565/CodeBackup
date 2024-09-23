#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, n;
    cin >> a >> b >> n;

    if (b == 0)
    {
        cout << 0;
    }
    else if (a == 0)
    {
        cout << "No solution" << endl;
    }
    else
    {
        for (int i = -1000; i <= 1000; i++)
        {
            if ((int)pow(i, n) * a == b)
            {
                cout << i << endl;
                return 0;
            }
        }
        cout << "No solution" << endl;
    }
    return 0;
}