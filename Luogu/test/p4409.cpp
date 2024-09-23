#include <bits/stdc++.h>
using namespace std;
long long a[20004] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    long long mymax = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << a[0] << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << a[0] + a[1] << endl;
        return 0;
    }
    if (n == 3)
    {
        cout << a[0] + a[1] + a[2] << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        mymax = max(mymax, a[i] + a[(i + 1) % n]);
    }
    cout << mymax << endl;
    return 0;
}