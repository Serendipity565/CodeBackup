#include<bits/stdc++.h>
using namespace std;
int n,a,b;
struct fuck
{
    int now;
    int mov;
    int k;
}f[210];
queue <fuck> s;
int bfs()
{
    int temp_now,temp_mov,temp_k;
    while (!s.empty())
    {
        temp_now=s.front().now;
        temp_mov=s.front().mov;
        temp_k=s.front().k;
        s.pop();
        if (temp_now-temp_mov>=1 && f[temp_now-temp_mov].k==-1)
        {
            if (temp_now-temp_mov==b)
            {
                return temp_k+1;
            }
            f[temp_now-temp_mov].k=temp_k+1;
            s.push(f[temp_now-temp_mov]);
        }
        if (temp_now+temp_mov<=n && f[temp_now+temp_mov].k==-1)
        {
            if (temp_now+temp_mov==b)
            {
                return temp_k+1;
            }
            f[temp_now+temp_mov].k=temp_k+1;
            s.push(f[temp_now+temp_mov]);
        }
    }
    return -1;
}
int main()
{
    scanf("%d %d %d",&n,&a,&b);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&f[i].mov);
        f[i].now=i;
        f[i].k=-1;
    }
    if (a==b)
    {
        printf("%d",0);
        return 0;
    }
    f[a].k=0;
    s.push(f[a]);
    printf("%d",bfs());
    return 0;
}