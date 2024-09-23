#include<bits/stdc++.h>
using namespace std;
int a[5000006];
int b[5000006];
int main()
{
	int n,m;
	a[0]=0;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i]-a[i-1];
	}
	int l,r,q;
	for (int i=0;i<m;i++)
	{
		scanf("%d %d %d",&l,&r,&q);
		b[l]+=q;
		b[r+1]-=q;
	}
	for (int i=1;i<=n;i++)
	{
		a[i]=b[i]+a[i-1];
	}
	int mymin=a[1];
	for (int i=2;i<=n;i++)
	{
		if (a[i]<mymin) mymin=a[i];
	}
	printf("%d",mymin);
	return 0;
}