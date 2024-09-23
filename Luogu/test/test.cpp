#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
    int T;
    bool flag;
    char temp;
    cin >> T;
    while (T--)
    {
        int r = 0;
        char s[15];
        flag = 0;
        fflush(stdin);
        gets(s);
        for (int i = 0; i < strlen(s) - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                flag = 1;
                r = i;
            }
            if (flag == 1)
            {
                temp = s[r];
                s[r] = s[r + 1];
                s[r + 1] = temp;
                cout << "YES" << endl;
                puts(s);
                break;
            }
        }
        if (flag == 0)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}