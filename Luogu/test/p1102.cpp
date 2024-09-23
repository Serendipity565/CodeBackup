#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200010],c;
ll ans;
map<int,ll> m;
int main(){
	int n;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m[a[i]]++;
		a[i]-=c;
	}
	for(int i=1;i<=n;i++){
		ans+=m[a[i]];
	}
	cout<<ans<<endl;
	return 0;
	
}