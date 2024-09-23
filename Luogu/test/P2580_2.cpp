#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int q, n, trie[500010][65], exist[500010], cnt;
string s;

int getnum(char x)
{
    if (x >= 'A' && x <= 'Z')
    {
        return x - 'A';
    }
    else if (x >= 'a' && x <= 'z')
    {
        return x - 'a' + 26;
    }
    else
    {
        return x - '0' + 52;
    }
}

void insert(string s)
{
    int p = 0, len = s.size();
    for (int i = 0; i < len; i++)
    {
        int c = getnum(s[i]);
        if (!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }
        p = trie[p][c];
    }
    exist[p]++;
}

int find(string s)
{
    int p = 0, len = s.size();
    for (int i = 0; i < len; i++)
    {
        int c = getnum(s[i]);
        if (!trie[p][c])
        {
            return 0;
        }
        p = trie[p][c];
    }
    return exist[p];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        insert(s);
    }
    cin >> q;
    map<string, int> mp;
    for (int i = 1; i <= q; i++)
    {
        cin >> s;
        int k = find(s);
        if (mp.find(s) != mp.end())
        {
            cout << "REPEAT" << endl;
        }
        else if (k == 1)
        {
            cout << "OK" << endl;
            mp[s]++;
        }
        else if (k == 0)
        {
            cout << "WRONG" << endl;
        }
    }
    return;
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