#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i <= (n - 2) / 2; i++)
    {
        if (i != (n - 2 - i))
        {
            ans += i * (n - i - 2) * 2;
        }
        else
        {
            ans += i * (n - i - 2);
        }
    }

    if (n <= 3)
    {
        cout << 0;
    }
    else
    {
        cout << n * ans / 4;
    }

    return 0;
}