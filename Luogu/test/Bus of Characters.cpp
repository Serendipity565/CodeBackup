#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	priority_queue<int, vector<int>, greater<int> > q;
	priority_queue<int> p;
	map<int,int> m;
	int a;

	for (int i=0;i<n;i++)
	{
		cin>>a;
		m[a]=i+1;
		q.push(a);
	}
	string s;
	cin>>s;
	for (int i=0;i<2*n;i++)
	{
		if (s[i]=='0')
		{
			a=q.top();
			cout<<m[a]<<" ";
			q.pop();
			p.push(a);
		}
		else
		{
			a=p.top();
			cout<<m[a]<<" ";
			p.pop();
		}
	}
	return 0;
}