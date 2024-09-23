#include<bits/stdc++.h>
using namespace std;

int a[100005];
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{
    int n;
    n=read();
    for (int i=0;i<n;i++)
    {
        a[i]=read();
    }
    sort(a,a+n);
    deque<int> q[n];
    int k=0;
    for (int i=0;i<n;i++)
    {
        int k1=-1;
        int len=100000;
        for (int j=max(0,k-100);j<k;j++)
        {
            if (q[j].back()==a[i]-1 && q[j].size()<len) k1=j;
        }
        if (k1<0)
        {
            q[k].push_back(a[i]);
            k++;
        }
        else
        {
            q[k1].push_back(a[i]);
        }
    }
    int sum=100000;
    for (int i=0;i<k;i++)
    {
        if (q[i].size()<sum) sum=q[i].size();
    }
    cout<<sum;
    return 0;
}