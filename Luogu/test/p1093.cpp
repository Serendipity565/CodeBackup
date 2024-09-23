#include <bits/stdc++.h>
using namespace std;

struct stu
{
    int num;
    int yue,shu,yin;
    int sum;
}student[310];

bool cmp(stu a,stu b)
{
    if (a.sum>b.sum) return 1;
    else if (a.sum<b.sum) return 0;
    else{
        if (a.yue>b.yue) return 1;
        else if (a.yue<b.yue) return 0;
        else{
            if (a.num<b.num) return 1;
            else return 0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>student[i].yue>>student[i].shu>>student[i].yin;
        student[i].sum=student[i].yue+student[i].shu+student[i].yin;
        student[i].num=i+1;
    }
    sort(student,student+n,cmp);
    for (int i=0;i<5;i++)
    {
        cout<<student[i].num<<" "<<student[i].sum<<endl;
    }
    return 0;
}