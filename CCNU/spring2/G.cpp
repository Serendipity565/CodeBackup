#include<bits/stdc++.h>
using namespace std;
map <long long,long long>x;

int main()
{
    int n;
    int xi,yi;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf(" %d %d",&xi,&yi);
        x[xi+yi]++;
    }
    long long k=0;
    long long sum=0;
    for (auto i : x)
    {
        
        k+=sum*i.second;
        sum+=i.second;
    }
    cout<<k+x.size()-1;
    return 0;
}