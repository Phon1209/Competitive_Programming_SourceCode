#include<bits/stdc++.h>
unsigned long long fi(int);
unsigned long long a[100];
int main()
{
	int t;
	int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		fi(n);
			printf("%llu\n",a[n]);
	}
}
unsigned long long fi(int n)
{
	if(n<=1)
	{
		a[n]=1;
		return 1;
	}
	if(a[n]!=0)
	{
		return a[n];
	}
	a[n]=fi(n-1)+fi(n-2);
	return a[n];
}
