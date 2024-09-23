#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = n * n;
    int a;
    int k = 0;
    int q = 0;
    while (sum > 0)
    {
        cin >> a;
        sum -= a;
        while (a > 0)
        {
            cout << q;
            a--;
            k++;
            if (k == n)
            {
                cout << endl;
                k = 0;
            }
        }
        q = (q + 1) % 2;
    }
    return 0;
}
