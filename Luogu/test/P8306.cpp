#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int q, n, trie[3000005][65], exist[3000005], cnt;
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
        exist[p]++;
    }
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
    for (int i = 0; i <= cnt; i++)
    {
        exist[i] = 0;
        for (int j = 0; j <= 122; j++)
        {
            trie[i][j] = 0;
        }
    }

    cnt = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        insert(s);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> s;
        cout << find(s) << endl;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}