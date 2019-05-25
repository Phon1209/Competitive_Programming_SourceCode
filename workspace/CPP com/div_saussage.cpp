#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int c=1;
	for(int i=2;i<=n;i++)
		if(n%i==0 && m%i==0)
			while(n%i==0 && m%i==0)
			{
				n/=i;
				m/=i;
				c*=i;
			}
	printf("%d\n",(m-1)*c);
}
