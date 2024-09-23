#include <bits/stdc++.h>
using namespace std;

struct student
{
    string name;
    int score1;
    int socre2;
    int score3;
    int sum;
}stu[1010];

int main()
{
    int n,max=0,res=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>stu[i].name>>stu[i].score1>>stu[i].socre2>>stu[i].score3;
        stu[i].sum=stu[i].score1+stu[i].socre2+stu[i].score3;
        if (stu[i].sum>res)
        {
            res=stu[i].sum;
            max=i;
        }
    }
    cout<<stu[max].name<<" "<<stu[max].score1<<" "<<stu[max].socre2<<" "<<stu[max].score3;
    return 0;
}