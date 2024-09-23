#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long h;
    cin >> h;
    long long a = 1;
    int cnt = 1;
    while (a <= h)
    {
        a = (a << 1) + 1;
        cnt++;
    }
    cout << cnt;
    return 0;
}