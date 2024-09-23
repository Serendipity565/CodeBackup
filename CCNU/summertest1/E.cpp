#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

struct p
{
    int a;
    int b;
    int c;
} wu[200005];
bool cmp(p p1, p p2)
{
    if (p1.c < p2.c)
    {
        return true;
    }

    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> wu[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> wu[i].b;
        wu[i].c = wu[i].a - wu[i].b;
    }
    sort(wu + 1, wu + 1 + n, cmp);
    ll sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += wu[i].a;
    }
    for (int i = k + 1; i <= n; i++)
    {
        sum += min(wu[i].a, wu[i].b);
    }
    cout << sum;
    return 0;
}