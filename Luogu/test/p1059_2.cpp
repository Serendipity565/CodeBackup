#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	set<int> a;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>m;
		a.insert(m);
	}
	cout<<a.size()<<endl;
	for (auto it=a.begin();it!=a.end();it++)
	{
		cout<<*it<<" ";
	}
	return 0;
}