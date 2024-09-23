#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
struct p
{
    int a;
    int b;
} pai[10004];
bool cmp(p p1, p p2)
{
    if (p1.b > p2.b)
    {
        return true;
    }
    else if (p1.b == p2.b && p1.a > p2.a)
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pai[i].a >> pai[i].b;
    }
    sort(pai + 1, pai + 1 + n, cmp);
    int cnt = 1;
    int i = 1;
    ll sum = 0;
    while (cnt && i <= n)
    {
        cnt--;
        cnt += pai[i].b;
        sum += pai[i].a;
        i++;
    }
    cout << sum << endl;
    return 0;
}