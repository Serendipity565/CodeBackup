#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
int trie[3000010][2], a[100010], cnt;

void insert(int num)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int c = (num >> i) & 1;
        if (!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }
        p = trie[p][c];
    }
    return;
}

int find(int num)
{
    int p = 0;
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int c = (num >> i) & 1;
        if (trie[p][!c])
        {
            ans = ans * 2 + 1;
            p = trie[p][!c];
        }
        else
        {
            ans *= 2;
            p = trie[p][c];
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int mymax = 0;
    for (int i = 1; i <= n; i++)
    {
        mymax = max(find(a[i]), mymax);
    }
    cout << mymax << endl;
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