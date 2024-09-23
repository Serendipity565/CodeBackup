#include <bits/stdc++.h>
using namespace std;

int res[500010]={0};
int temp[500010]={0};
long long sum=0;

void msort(int l,int r)
{
    if (l<r)    //划分
    {
        int mid=(l+r)/2;
        msort(l,mid);
        msort(mid+1,r);

        //开始合并
        int l1=l,r1=mid+1;
        int k=l;
        while (l1<=mid && r1<=r)
        {
            if (res[l1]<=res[r1])
            {
                temp[k]=res[l1];
                k++;l1++;
            }
            else
            {
                temp[k]=res[r1];
                k++;r1++;
                sum=sum+mid-l1+1;
            }
        }

        //合并多余元素
        while (l1<=mid)
        {
            temp[k]=res[l1];
            k++;l1++;
        }
        while (r1<=r)
        {
            temp[k]=res[r1];
            k++;r1++;
        }

        //储存临时数组
        for(int i=l;i<=r;i++)
        {
            res[i]=temp[i];
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
        cin>>res[i];
    }
    msort(0,n-1);
    cout<<sum;
    return 0;
}