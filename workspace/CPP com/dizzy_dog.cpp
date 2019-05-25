#include<stdio.h>
unsigned long long a[55];
int main()
{
	int n;
	scanf("%d",&n);
	a[0]=1;
	a[1]=3;
	for(int i=2;i<=n;i++)
	{
		a[i]=(2*a[i-1])+a[i-2];
	}
//	for(int i=0;i<=50;i++)
		printf("%llu\n",a[n]);
}
