#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (s1[0] == s3[2] && s1[1] == s3[1] && s1[2] == s3[0] && s2[0] == s2[2])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
