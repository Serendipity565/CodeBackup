#include <bits/stdc++.h>
using namespace std;
int n;
bool check(string s1, string s2)
{
    for (int i = 0; i < s1.length(); i++)
    {
        if (s2.find(s1.substr(i)))
        {
            return true;
        }
    }
    return false;
}

void dfs(string s1, int len)
{
    for (int i = 1; i < n; i++)
    {
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string s[30];
    int a[30] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
}