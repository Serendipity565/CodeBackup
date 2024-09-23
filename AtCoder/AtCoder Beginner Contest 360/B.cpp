#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool flag = false;
    string s, t;
    cin >> s >> t;

    for (int w = 1; w < s.size(); w++) // 划分
    {
        for (int c = 1; c <= w; c++)
        {
            string temp = "";
            for (int i = c - 1; i < s.size(); i += w)
            {
                temp += s[i];
            }
            if (temp == t)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}