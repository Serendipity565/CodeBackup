#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,a,b;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		set<int> m;
		cin>>b;
		for (int i=1;i<=b;i++)
		{
			cin>>a;
			if (m.find(a)==m.end()) cout<<a<<" ";
			m.insert(a);
		}
	cout<<endl;
	}
	return 0;
}