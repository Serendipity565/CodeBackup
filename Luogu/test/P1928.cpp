#include <bits/stdc++.h>
using namespace std;
stack<char> stk;
string repeat(string s, int k)
{
    string ans = "";
    for (int i = 1; i <= k; i++)
    {
        ans += s;
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    int l = 0;
    int r = 0;
    string temp = "";
    string ans = "";
    string num = "";
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == '[')
        {
            stk.push(s[i]);
            l++;
            i++;
        }
        else
        {
            ans += s[i];
            i++;
        }
        while (l > 0)
        {
            while (s[i] != ']')
            {
                if (s[i] == '[')
                {
                    l++;
                }
                stk.push(s[i]);
                i++;
            }
            i++;
            l--;
            while (stk.top() > '9' || stk.top() < '0')
            {
                temp.insert(0, 1, stk.top());
                stk.pop();
            }
            while (stk.top() <= '9' && stk.top() >= '0')
            {
                num.insert(0, 1, stk.top());
                stk.pop();
            }
            stk.pop();
            temp = repeat(temp, stoi(num));
            if (l != 0)
            {
                for (int j = 0; j < temp.size(); j++)
                {
                    stk.push(temp[j]);
                }
            }
            else
            {
                ans += temp;
            }
            temp = "";
            num = "";
        }
    }
    cout << ans << endl;
    return 0;
}