#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void debug()
{
    return;
}

void solve()
{
    int x;
    int y;
    cin>>x;
    if(x<=30)
        if((x>20))y=x;
        else if(x>10) y=2*x;
    if(x>0&& x<30)cout<<x<<y;
    else cout<<"wa"<<endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}