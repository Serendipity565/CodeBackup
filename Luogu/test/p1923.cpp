#include <bits/stdc++.h>
using namespace std;

int a[5000010]={0};

void qsort(int l,int r,int m)
{
    if (l>=r) return;
    int k=r;
    int i=l,j=r;
    while (1)
    {
        while (a[i]<=a[k] && i<j) i++;
        while (a[j]>=a[k] && i<j) j--;
        if (i<j)
        {
            swap(a[i],a[j]);
        }
        else 
        {
            swap(a[j],a[k]);
            break;
        }
    }
    if (m<j) qsort(l,j-1,m);
    else if (m>i) qsort(i+1,r,m);
    else return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n;
    cin>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    qsort(0,n-1,m);
    cout<<a[m];
    return 0;
}