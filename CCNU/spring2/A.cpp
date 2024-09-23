#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m; string s;
    cin >> s >> m;
    m %= s.size();
    for (int i = 0; i < s.size(); i++)
        cout << s[(i + m) % s.size()];
    return 0;
}