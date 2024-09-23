#include<bits/stdc++.h>
using namespace std;
int a[1005]={0};
void my_get(int num) {
    a[num]=1;
    for (int i=1;i<=num/2;i++) {
        if (a[i]!=0) {
            a[num]+=a[i];
        }
        else {
            my_get(i);
            a[num]+=a[i];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    a[1]=1;
    a[2]=2;
    my_get(n);
    cout<<a[n];
    return 0;
}