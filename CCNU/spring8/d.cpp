#include <bits/stdc++.h>
using namespace std;

int n;
int k;
struct d
{
    int high;
    bool pos; // 1表示可以到达
    bool w;   // 表示左右墙壁，1为左
    int time;
};

d d1[100005];
d d2[100005];
bool flag = false;

void bfs()
{
    d d0;
    d0.high = 1;
    d0.pos = 1;
    d0.w = 1;
    d0.time = 1;
    queue<d> q;
    q.push(d0);
    while (q.size())
    {

        d0 = q.front();
        q.pop();
        if (d0.w == 1)
        {
            if (d0.high + k > n || (d0.high + k == n && d2[d0.high + k].pos == 1))
            {
                flag = true;
                return;
            }
            else if (d2[d0.high + k].pos == 1)
            {
                d2[d0.high + k].time = d0.time + 1;
                d2[d0.high + k].pos = 0;
                q.push(d2[d0.high + k]);
            }
            if (d1[d0.high + 1].pos == 1)
            {
                if (d0.high + 1 == n)
                {
                    flag = true;
                    return;
                }
                else
                {
                    d1[d0.high + 1].time = d0.time + 1;
                    d1[d0.high + 1].pos = 0;
                    q.push(d1[d0.high + 1]);
                }
            }
            if (d1[d0.high - 1].pos == 1 && (d0.high - 1) >= d0.time + 1)
            {
                d1[d0.high - 1].time = d0.time + 1;
                d1[d0.high - 1].pos = 0;
                q.push(d1[d0.high - 1]);
            }
        }
        if (d0.w == 0)
        {
            if (d0.high + k > n || (d0.high + k == n && d1[d0.high + k].pos == 1))
            {
                flag = true;
                return;
            }
            else if (d1[d0.high + k].pos == 1)
            {
                d1[d0.high + k].time = d0.time + 1;
                d1[d0.high + k].pos = 0;
                q.push(d1[d0.high + k]);
            }
            if (d2[d0.high + 1].pos == 1)
            {
                if (d0.high + 1 == n)
                {
                    flag = true;
                    return;
                }
                else
                {
                    d2[d0.high + 1].time = d0.time + 1;
                    d2[d0.high + 1].pos = 0;
                    q.push(d2[d0.high + 1]);
                }
            }
            if (d2[d0.high - 1].pos == 1 && (d0.high - 1) >= d0.time + 1)
            {
                d2[d0.high - 1].time = d0.time + 1;
                d2[d0.high - 1].pos = 0;
                q.push(d2[d0.high - 1]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;

    for (int i = 0; i < n; i++)
    {
        if (s1[i] == 'X')
        {
            d1[i + 1].pos = 0;
        }
        else
        {
            d1[i + 1].pos = 1;
        }
        if (s2[i] == 'X')
        {
            d2[i + 1].pos = 0;
        }
        else
        {
            d2[i + 1].pos = 1;
        }
        d1[i + 1].high = i + 1;
        d1[i + 1].w = 1;
        d2[i + 1].high = i + 1;
        d2[i + 1].w = 0;
    }
    bfs();
    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}