#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int li[100005] = {0};
int ri[100005] = {0};

void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0;
    int r = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            l++;
            li[l] = i;
        }
        else if (s[i] == ')')
        {
            r++;
            ri[r] = i;
        }
        else if (s[i] == '_')
        {
            if (l <= r)
            {
                s[i] = '(';
                l++;
                li[l] = i;
            }
            else
            {
                s[i] = ')';
                r++;
                ri[r] = i;
            }
        }
    }
    ll cnt = 0;
    for (int i = 1; i <= l; i++)
    {
        // cout << li[i] << " " << ri[i] << endl;
        cnt += ri[i] - li[i];
    }
    cout << cnt << endl;
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