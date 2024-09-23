#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    a = ' ' + a + ' ';
    b = ' ' + b + ' ';
    int sum = 0;
    if (b.find(a) == string::npos)
    {
        cout << -1 << endl;
    }
    else
    {
        int k = b.find(a);
        int p = b.find(a);
        while (p != string::npos)
        {
            sum++;
            p = b.find(a, p + 1);
        }
        cout << sum << " " << k << endl;
    }
    return 0;
}