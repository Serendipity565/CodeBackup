#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
int a[1000006] = {0};
map<int, int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int sum = n;
    int j = 1;
    int l = 1;
    int r = n;
    for (int i = 1; i <= n; i++)
    {
        while (mp.size() < m && j <= n)
        {
            mp[a[j]]++;
            j++;
        }
        if (j <= n)
        {
            if (j - i + 1 < sum)
            {
                l = i;
                r = j - 1;
                sum = j - i + 1;
            }
            mp[a[i]]--;
            if (mp[a[i]] == 0)
            {
                mp.erase(a[i]);
            }
        }
        else
        {
            break;
        }
    }
    cout << l << " " << r << endl;
    return 0;
}