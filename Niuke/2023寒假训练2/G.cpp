#include<bits/stdc++.h>
using namespace std;
struct off
{
    int a;
    long long b;
}o[100005];
bool cmp(off x,off y)
{
    return x.a<y.a;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        int n;int m;
        scanf(" %d %d",&n,&m);
        long long sum=m;
        for (int i=1;i<=n;i++)
        {
            scanf(" %d %d",&o[i].a,&o[i].b);
        }
        sort(o+1,o+1+n,cmp);
        for (int i=2;i<=n;i++)
        {
            o[i].b+=o[i-1].b;
        }
        for (int i=1;i<=n;i++)
        {
            if (o[i].b-o[i].a<m && o[i].b-o[i].a>=0)
            {
                sum=max(o[i].b+m,sum);
            }
            else if (o[i].a-o[i].b<=m)
            {
                sum=max(o[i].b+m,sum);
            }
        }
        cout<<sum<<endl;
        t--;
    }
}