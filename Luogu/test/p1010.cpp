#include <bits/stdc++.h>
using namespace std;
string got(int n)
{
    if (n == 0)
    {
        return "2(0)";
    }
    if (n == 1)
    {
        return "2";
    }
    string s = "";
    int k = 0;
    while (n)
    {
        int temp = n % 2;
        n /= 2;
        if (temp)
        {
            s = got(k) + s;
            if (n)
            {
                s = '+' + s;
            }
        }
        k++;
    }
    return "2(" + s + ")";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s = "";
    int n;
    cin >> n;
    int k = 0;
    while (n)
    {
        int temp = n % 2;
        n /= 2;
        if (temp)
        {
            s = got(k) + s;
            if (n)
            {
                s = '+' + s;
            }
        }
        k++;
    }
    cout << s << endl;
}