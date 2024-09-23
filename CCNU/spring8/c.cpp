#include <bits/stdc++.h>
using namespace std;
int a[2005] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int mymax = 1;
    for (int i = 1; i <= n; i++)
    {
        int temp = 1;
        int next = a[i];
        while (next != -1)
        {
            temp++;
            next = a[next];
        }
        mymax = max(temp, mymax);
    }
    cout << mymax;
    return 0;
}