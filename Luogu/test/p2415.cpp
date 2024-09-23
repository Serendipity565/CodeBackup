#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    getline(cin, a);
    long long sum = 0;
    int n = 0;
    int m = 0;
    for (long long i = 0; i <= a.size(); i++)
    {
        if (a[i] <= '9' && a[i] >= '0')
        {
            n = n * 10 + (a[i] - '0');
        }
        else if (a[i] == ' ')
        {
            sum += n;
            n = 0;
            m++;
        }
        else if (a[i] == '\0')
        {
            sum += n;
            n = 0;
            m++;
            break;
        }
    }

    sum = sum * pow(2, m - 1);
    cout << sum;
    return 0;
}