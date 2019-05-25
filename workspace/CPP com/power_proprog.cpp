#include<bits/stdc++.h>
unsigned long long pw(int,int);
int c;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d %d %d",&a,&b,&c);
		printf("%llu\n",pw(a,b));
	}
}
unsigned long long pw(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	int x=pw(a,b/2);
	x%=c;
	x*=x;
	x%=c;
	if(b%2)
		x*=a;
	return x%c;
}
