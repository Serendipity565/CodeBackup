#include <bits/stdc++.h>
using namespace std;

struct k
{
    long long q;
    long long a;
    long long c;
    bool t;
} stu[200005];

bool cmp(k k1, k k2)
{
    return k1.c < k2.c;
}
bool cmp2(k k1, k k2)
{
    return k1.q < k2.q;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    long long cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> stu[i].a >> stu[i].c;
        stu[i].q = i;
        stu[i].t = false;
    }
    sort(stu + 1, stu + n + 1, cmp);
    long long mymax = stu[1].a;
    for (int i = 2; i <= n; i++)
    {
        if (stu[i].a < mymax)
        {
            stu[i].t = true;
        }
        else
        {
            cnt++;
            mymax = stu[i].a;
        }
    }
    sort(stu + 1, stu + 1 + n, cmp2);
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
    {
        if (stu[i].t == false)
        {
            cout << stu[i].q << " ";
        }
    }
    return 0;
}