#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
vector<string> y;
vector<string> s;
int check(int k)
{
    string a = y[k];
    int i = 0;
    while (i < a.size())
    {
        if (a[i] == '<')
        {
            a.erase(i, 1);
            if (i > 0)
            {
                a.erase(i - 1, 1);
                i--;
            }
            i--;
        }
        i++;
    }
    string b = s[k];
    i = 0;
    while (i < b.size())
    {
        if (b[i] == '<')
        {
            b.erase(i, 1);
            if (i > 0)
            {
                b.erase(i - 1, 1);
                i--;
            }
            i--;
        }
        i++;
    }

    int sum = 0;
    int j = 0;
    i = 0;
    while (i < a.size())
    {
        if (j >= b.size())
        {
            return sum;
        }
        if (a[i] == b[j])
        {

            sum++;
            j++;
            i++;
        }
        else if (j + 2 < b.size() && a[i] != b[j] && a[i] == b[j + 2] && b[j + 1] == '<')
        {
            sum++;
            j += 3;
            i++;
        }
        else
        {
            j++;
            i++;
        }
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string test;
    getline(cin, test);
    while (test != "EOF")
    {
        y.push_back(test);
        getline(cin, test);
    }
    getline(cin, test);
    while (test != "EOF")
    {
        s.push_back(test);
        getline(cin, test);
    }
    int time;
    cin >> time;
    ll sum = 0;
    for (int i = 0; i < y.size(); i++)
    {
        sum += check(i);
        // cout << sum << endl;
    }
    ll ans = round((double)(sum) / time * 60);
    cout << ans;
    return 0;
}