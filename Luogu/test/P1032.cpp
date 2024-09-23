#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

string ai[10];
string bi[10];

struct node
{
    string s;
    int num;
};

string trans(string str, int i, int j)
{
    string ans = "";
    if (i + ai[j].length() > str.length())
    {
        return ans;
    }
    for (int k = 0; k < ai[j].size(); k++)
    {
        if (str[i + k] != ai[j][k])
        {
            return ans;
        }
    }
    ans = str.substr(0, i) + bi[j] + str.substr(i + ai[j].size());
    return ans;
}

void solve()
{
    string a, b;
    cin >> a >> b;

    string tempa, tempb;
    int k = 1;
    while (cin >> tempa >> tempb)
    {
        ai[k] = tempa;
        bi[k] = tempb;
        k++;
    }
    node temp;
    queue<node> q;
    map<string, int> ma;
    q.push({a, 0});
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp.s == b)
        {
            cout << temp.num << endl;
            return;
        }
        if (temp.num > 10)
        {
            cout << "NO ANSWER!" << endl;
            return;
        }
        for (int i = 0; i < temp.s.size(); i++)
        {
            for (int j = 1; j < k; j++)
            {
                string st = trans(temp.s, i, j);
                if (st != "")
                {
                    if (ma.count(st) == 0)
                    {
                        q.push({st, temp.num + 1});
                        ma[st] = 1;
                    }
                }
            }
        }
    }
    cout << "NO ANSWER!" << endl;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}