#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin>>N;
	for (int i=0;i<N;i++)
	{
		int n,c;
		cin>>n>>c;
		long long a[200005],sum=0;
		cin>>a[1];
		for (int i=2;i<=n;i++)
		{
			cin>>a[i];
			a[i]=i*c-a[i];
		}
		sort(a+2,a+n+1);
		int k=2;
		while (k<=n)
		{
			if (sum+a[1]>=a[k]) 
			{
				sum+=c*k-a[k];
				k++;
			}
			else
			{
				cout<<"No"<<endl;
				break;
			}
		}
		if (k==n+1)
		{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}