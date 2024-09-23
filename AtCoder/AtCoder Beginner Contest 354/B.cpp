#include <bits/stdc++.h>
using namespace std;
string stu[105];

bool cmp(string a, string b)
{
    return a < b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    long long temp;
    long long s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> stu[i] >> temp;
        s += temp;
    }
    s %= n;
    sort(stu + 1, stu + 1 + n);
    cout << stu[s + 1];
    return 0;
}