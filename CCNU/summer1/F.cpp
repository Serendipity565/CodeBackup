#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

void solve()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    ll sum = 0;
    map<int, int> mp1;
    // map<int, int> mp2;
    for (int i = 0; i < s1.size(); i++)
    {
        mp1[s1[i] - '0']++;
    }
    for (auto i : mp1)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            int temp = i.first * (s2[j] - '0');
            temp = temp / 10 + temp % 10;
            sum += temp * i.second;
        }
    }
    // cout << sum << endl;
    while (sum >= 10)
    {
        ll p = 0;
        while (sum > 0)
        {
            p += sum % 10;
            sum /= 10;
        }
        sum = p;
    }
    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}