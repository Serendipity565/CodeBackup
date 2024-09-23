#include <bits/stdc++.h>
using namespace std;

int main()
{
    char y1, y2;
    int x1, x2;
    cin >> y1 >> x1;
    cin >> y2 >> x2;
    int y = y2 - y1;
    int x = x2 - x1;
    cout << max(abs(x), abs(y)) << endl;
    string s;
    for (int i = 1; i <= abs(min(abs(x), abs(y))); i++)
    {
        s = "";
        if (y > 0)
        {
            s += 'R';
        }
        else if (y < 0)
        {
            s += 'L';
        }
        if (x > 0)
        {
            s += 'U';
        }
        else if (x < 0)
        {
            s += 'D';
        }
        cout << s << endl;
    }

    for (int i = (min(abs(x), abs(y))) + 1; i <= (max(abs(x), abs(y))); i++)
    {
        if (abs(y) < abs(x))
        {
            y = 0;
        }
        else
        {
            x = 0;
        }
        s = "";
        if (y > 0)
        {
            s += 'R';
        }
        else if (y < 0)
        {
            s += 'L';
        }
        if (x > 0)
        {
            s += 'U';
        }
        else if (x < 0)
        {
            s += 'D';
        }
        cout << s << endl;
    }
    return 0;
}
