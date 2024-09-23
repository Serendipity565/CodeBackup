#include <bits/stdc++.h>
using namespace std;
int check(int a, int b, int c)
{
    int mymax = a;
    if (b > mymax)
    {
        mymax = b;
    }
    if (c > mymax)
    {
        mymax = c;
    }

    if (mymax < (a + b + c - mymax))
    {
        return 1;
    }
    if (mymax == (a + b + c - mymax))
    {
        return 2;
    }

    return 3;
}
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (check(a, b, c) == 1 || check(b, c, d) == 1 || check(a, c, d) == 1 || check(a, b, d) == 1)
    {
        cout << "TRIANGLE" << endl;
        return 0;
    }
    else if (check(a, b, c) == 2 || check(b, c, d) == 2 || check(a, c, d) == 2 || check(a, b, d) == 2)
    {
        cout << "SEGMENT" << endl;
        return 0;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
}
