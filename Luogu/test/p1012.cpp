#include <bits/stdc++.h>
using namespace std;

int a[25];

bool cmp(int a,int b)
{
    string a_ =to_string(a);
    string b_ =to_string(b);
    int m=min(a_.length(),b_.length());
    for (int i=0;i<m;i++)
    {
        if (a_[i]>b_[i])
        {
            return 1;
        }
        else if (a_[i]<b_[i])
        {
            return 0;
        }
    }
    if (a_.length()<b_.length())
    {
        if (b_[0]>b_[a_.length()])
        {
            return 1;
        }
        else return 0;
    }
    else
    {
        if (a_[0]>a_[b_.length()])
        {
            return 1;
        }
        else return 0;
    }
}

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for (int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}