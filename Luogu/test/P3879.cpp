#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

struct P3879
{
    int trie[5003][65] = {0};
    bool exist[15003] = {0};
    int cnt = 0;

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
        exist[p] = true;
    }

    bool find(string s)
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
} a[1003];

void solve()
{
    int n;
    int q;
    string s;
    cin >> n;
    int m;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            cin >> s;
            a[i].insert(s);
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> s;
        int k = 1;
        for (int j = 1; j <= n; j++)
        {
            if (a[j].find(s))
            {
                if (k == 1)
                {
                    cout << j;
                    k++;
                }
                else
                {
                    cout << " " << j;
                }
            }
        }
        cout << endl;
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