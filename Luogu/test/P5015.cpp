#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    ll sum = 0;
    while (cin >> s)
    {
        sum += s.size();
    }
    cout << sum << endl;
    return 0;
}