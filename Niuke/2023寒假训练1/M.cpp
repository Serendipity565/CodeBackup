#include<bits/stdc++.h>
using namespace std;
int st[3][100005]={0};
void solve()
{
    int n;
    memset(st,0,sizeof(st));
    for (int i=1;i<=n;i++)
    {
        scanf(" %d",&st[0][i]);
    }
    for (int i=1;i<=n;i++)
    {
        scanf(" %d",&st[1][i]);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}