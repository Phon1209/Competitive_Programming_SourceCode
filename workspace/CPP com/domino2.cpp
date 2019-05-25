#include<bits/stdc++.h>
int fi(int);
int a[100005],b[100005];
int main()
{
	int t;
	int n;
	scanf("%d",&t);
	int cnt=1;
	for(int i=0;i<=100000;i++)
	{
		
//		printf("%d\n",cnt);
		b[i]=(fi(i)*cnt)%13345;
		cnt*=2;
		cnt%=13345;
//		system("pause");
	}
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",(b[n])%13345);
	}
}
int fi(int n)
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
	a[n]=((fi(n-1)%13345)+(fi(n-2)%13345))%13345;
	return a[n];
}
