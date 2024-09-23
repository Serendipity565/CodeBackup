#include<bits/stdc++.h>
using namespace std;
int fa[5005]={0};
int find(int x)
{
    if (x==fa[x])
    {
        return x;
    }
    else
    {
        return find(fa[x]);
    }
}
void merge(int x,int y)
{
    x=find(x);
    y=find(y);
    if (x!=y)
    {
        fa[x]=y;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,p;
    cin>>n>>m>>p;
    for (int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    int mi,mj;
    for (int i=1;i<=m;i++)
    {
        cin>>mi>>mj;
        merge(mi,mj);
    }
    for (int i=1;i<=p;i++)
    {
        cin>>mi>>mj;
        if (find(mi)==find(mj))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}