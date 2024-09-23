#include <bits/stdc++.h>
using namespace std;

struct apple
{
    int x;
    int y;
}apples[5005];

bool cmp(apple a,apple b)
{
    return a.y<b.y;
}

int main()
{
    int n,s;
    cin>>n>>s;
    int a,b;
    int sum=0;
    cin>>a>>b;
    for (int i=0;i<n;i++)
    {
        cin>>apples[i].x>>apples[i].y;
    }
    sort(apples,apples+n,cmp);
    int k=0;
    while (s>0 && k<=n-1)
    {
        if (a+b>=apples[k].x && s>=apples[k].y)
        {
            s-=apples[k].y;
            sum++;
            k++;
        }
        else if (s<apples[k].y) break;
        else k++;
    }
    cout<<sum;
    return 0;
}