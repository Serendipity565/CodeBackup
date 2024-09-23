#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

map<string, string> mp;

void solve()
{
    char c;
    string name;
    cin >> c;
    string father;
    while (c != '$')
    {
        cin >> name;
        if (c == '#')
        {
            father = name;
        }
        else if (c == '+')
        {
            mp[name] = father;
        }
        else if (c == '?')
        {
            if (mp.count(name) == 0)
            {
                cout << name << " " << name << endl;
            }
            else
            {
                while (mp.count(mp[name]) != 0)
                {
                    mp[name] = mp[mp[name]];
                }
                cout << name << " " << mp[name] << endl;
            }
        }
        cin >> c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}