#include<bits/stdc++.h>
using namespace std;
long long a[25][2]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1];  //0表示x，1表示y
    }
    int mymin=1000000;
    set<double> st;
    double k;
    for (int i=1;i<=n;i++)
    {
        int cnt=0;
        st.clear();
        for (int j=1;j<=n;j++)
        {
            if (i!=j)
            {
                if (a[i][0]==a[j][0])
                {
                    cnt=1;
                }
                else
                {
                    k=(a[i][1]-a[j][1])*1.0/(a[i][0]-a[j][0]);
                    st.insert(k);
                }
            }
        }
        if (st.size()+cnt<mymin)
        {
            mymin=st.size()+cnt;
        }
    }
    cout<<mymin<<endl;
    return 0;
}