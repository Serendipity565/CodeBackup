#include <bits/stdc++.h>
using namespace std;

int a[10005]={0};
int temp[10005]={0};
long long ans=0;

void bublle_sort(int l,int r)
{
    for (int i=r;i>l;i--)
    {
        for (int j=l;j<i;j++)
        {
            if (a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                ans++;
            }
        }
    }
    return;
}

void msort(int l,int r)
{
    if (l<r)
    {
        int mid=(l+r)/2;
        msort(l,mid);
        msort(mid+1,r);
        //开始合并
        int i=l,j=mid+1,k=l;
        while (i<=mid && j<=r)
        {
            if (a[i]<=a[j])
            {
                temp[k]=a[i];
                i++;k++;
            }
            else 
            {
                temp[k]=a[j];
                j++;k++;
                ans=ans+mid-i+1;
            }
        }
        while (i<=mid)
        {
            temp[k]=a[i];
            i++;k++;
        }
        while (j<=r)
        {
            temp[k]=a[j];
            k++;j++;
        }
        for (int i=l;i<=r;i++)
        {
        a[i]=temp[i];
        }
        return;
    }
    else return;
}

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    msort(0,n-1);
    cout<<ans;
    return 0;
}