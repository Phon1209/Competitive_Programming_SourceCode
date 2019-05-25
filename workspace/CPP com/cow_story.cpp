#include<stdio.h>

int main()
{
	long long p0=0,p1=0,p2=0,p3=0,p4=0,ans=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		p0+=p1;
		p1=p2;
		p2=p3;
		p3=p4;
		p4=1;
		p3+=p0;
//		printf("%lld %lld %lld %lld %lld\n",p0,p1,p2,p3,p4);
	}
	ans=p0+p1+p2+p3+p4;
	printf("%lld\n",ans);
}
