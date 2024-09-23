#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	map<string,string> map_1;
	string a,b;
	for (int i=0;i<m;i++)
	{
		cin>>a>>b;
		map_1[a]=b;
	}
	for (int i=0;i<n;i++)
	{
		cin>>a;
		if (a.length()>map_1[a].length())
		{
			cout<<map_1[a]<<" ";
		}
		else
		{
			cout<<a<<" ";
		}
	}
	return 0;
}