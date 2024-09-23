#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<ll> p;
    ll a;
    ll k = 0;
    cin >> a;
    while (a != 0)
    {
        p.push_back(a);
        k++;
        cin >> a;
    }
    for (int i = k - 1; i >= 0; i--)
    {
        cout << p[i] << " ";
    }
    return 0;
}