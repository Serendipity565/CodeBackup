#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int cnt = 0;
int r, c;
char s[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> r;
    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            cin >> s[i][j];
        }
    }
    for (int i = 1; i + 1 <= c; i++)
    {
        for (int j = 1; j + 1 <= r; j++)
        {
            int k = 0;
            if (s[i][j] == '.')
            {
                k++;
            }
            if (s[i + 1][j] == '.')
            {
                k++;
            }
            if (s[i][j + 1] == '.')
            {
                k++;
            }
            if (s[i + 1][j + 1] == '.')
            {
                k++;
            }
            if (k == 1)
            {
                cout << "Bad placement." << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            if (s[i][j] == '#' && s[i + 1][j] != '#' && s[i][j + 1] != '#')
            {
                cnt++;
            }
        }
    }
    cout << "There are " << cnt << " ships." << endl;
    return 0;
}