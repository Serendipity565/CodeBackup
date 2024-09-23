#include <bits/stdc++.h>
using namespace std;

int a[1000005] = {0};
bool vis[100000008] = {0};

void pre(int n)
{
    vector<int> prime;
    int num = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            num++;
        }
        for (int j = 1; j <= num && i * prime[j - 1] <= n; ++j)
        {
            vis[i * prime[j - 1]] = 1;
            if (i % prime[j - 1] == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    a[2] = 1;
    pre(m);
    for (int i = 3; i <= m; i++)
    {
        if (!vis[i])
        {
            a[i] = a[i - 1] + 1;
        }
        else
        {
            a[i] = a[i - 1];
        }
    }
    int l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        if (r > m || l < 1)
        {
            cout << "Crossing the line" << endl;
        }
        else
        {
            cout << a[r] - a[l - 1] << endl;
        }
    }
    return 0;
}