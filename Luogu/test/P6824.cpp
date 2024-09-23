#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

const int N = 1000006;
int n, k;
int a[N] = {0};
int exist[N * 21] = {0};
int trie[N * 21][2] = {0};
int cnt = 0;

void insert(int num)
{
    int p = 0;
    for (int i = 21; i >= 0; i--)
    {
        int c = (num >> i) & 1;
        if (!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }
        p = trie[p][c];
        exist[p]++;
    }
    return;
}

int find(int num)
{
    int ans = 0, p = 0;
    bool flag = 0;
    for (int i = 21, c; i >= 0; i--)
    {
        c = (num >> i) & 1;
        int t = (k >> i) & 1;
        if (t == 1)
        {
            ans += exist[trie[p][1 - (c ^ t)]];
        }
        if (!trie[p][c ^ t])
        {
            flag = 1;
            break;
        }
        p = trie[p][c ^ t];
    }
    if (!flag)
    {
        ans += exist[p];
    }
    return ans;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int mymax = 0;
    for (int i = 0; i < 2097152; i++)
    {
        mymax = max(mymax, find(i));
        if (mymax == n)
        {
            break;
        }
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