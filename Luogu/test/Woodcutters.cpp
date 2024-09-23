#include<bits/stdc++.h>
using namespace std;

struct trees
{
	int x;
	int h;
}tree[100005];

int main()
{
	int n;
	int res,ans=2;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>tree[i].x>>tree[i].h;
	}
	res=tree[0].x;
	for (int i=1;i<n-1;i++)
	{
		if (tree[i].x-tree[i].h>res)
		{
			res=tree[i].x;
			ans++;
		}
		else if (tree[i].x+tree[i].h<tree[i+1].x)
		{
			res=tree[i].x+tree[i].h;
			ans++;
		}
		else res=tree[i].x;
	}
	if (n==1)
	{
		cout<<1;
	}
	else cout<<ans;
	return 0;
}