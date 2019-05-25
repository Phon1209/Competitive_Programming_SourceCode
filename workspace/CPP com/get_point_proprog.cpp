#include<bits/stdc++.h>
unsigned long long find(int,int);
unsigned long long a[100][100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,p;
		scanf("%d %d %d",&n,&x,&p);
		printf("%llu\n",find(x-(n*p),n));
	}
}
unsigned long long find(int n,int m)
{
	if(a[n][m]!=0)
		return a[n][m];
	if(m==1)
		return 1;
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	unsigned long long ans=0;
	for(int i=0;i<=n;i++)
	{
		ans+=find(n-i,m-1);
	}
//	printf("%d %d %llu\n",n,m,ans);
	return a[n][m]=ans;
}
