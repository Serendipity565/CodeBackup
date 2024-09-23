#include <bits/stdc++.h>
using namespace std;
struct r
{
    long long a;
    long long b;
} h[28];

bool cmp(r h1, r h2)
{
    return h1.b > h2.b;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> h[i].a >> h[i].b;
    }
    sort(h + 1, h + 1 + m, cmp);
    long long sum = 0;
    int j = 1;
    while (n > 0)
    {
        sum += min(n, h[j].a) * h[j].b;
        n -= min(n, h[j].a);
        j++;
    }
    cout << sum << endl;
    return 0;
}