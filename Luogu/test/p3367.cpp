#include <bits/stdc++.h>
using namespace std;

// Compiler version g++ 6.3.0

int a[10004] = {0};
int find(int x)
{
    if (a[x] == x)
    {
        return x;
    }
    else
    {
        return a[x] = find(a[x]);
    }
}
void solve(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    a[fx] = fy;
}
bool check(int x, int y)
{
    return find(x) == find(y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    int x, y, z;
    for (int i = 1; i <= m; i++)
    {
        cin >> z >> x >> y;
        if (z == 1)
        {
            solve(x, y);
        }
        else
        {
            if (check(x, y))
            {
                cout << "Y" << "\n";
            }
            else
            {
                cout << "N" << "\n";
            }
        }
    }
    return 0;
}