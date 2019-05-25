#include<bits/stdc++.h>
unsigned int a[100005];
int main()
{
	a[0]=1;
	for(int i=0;i<=100000;i++)
	{
		a[i]%=2133134135;
		a[i+1]+=a[i];
		a[i+2]+=a[i];
		a[i]*=2;
		a[i]%=2133134135;
	}
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int s;
		scanf("%d",&s);
		printf("%u\n",a[s]);
	}
}
