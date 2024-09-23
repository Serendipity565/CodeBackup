#include <bits/stdc++.h>
using namespace std;
long long cnt = 0;
void check(long long m, long long n)
{

    if (m > n)
        return;
    else
        cnt++;
    check(m * 10, n);
    check(m * 10 + 1, n);
}
int main()
{
    long long n;
    cin >> n;

    check(1, n);
    cout << cnt;
}
