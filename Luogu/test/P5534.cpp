#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a1, a2;
    ll n;
    cin >> a1 >> a2 >> n;
    ll q = a2 - a1;
    cout << (a1 + a1 + (n - 1) * q) * n / 2;
    return 0;
}