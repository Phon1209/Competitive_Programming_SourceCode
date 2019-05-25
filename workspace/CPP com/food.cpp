#include<bits/stdc++.h>
bool use[25],ban[25];
int p[25];
void gen(int);
int n,a;
int main()
{
	int m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%d",&a),ban[a]=true;
	gen(0);
//	printf("B\n");
}
void gen(int lv)
{
	if(lv==n)
	{
		for(int i=0;i<n;i++)
			printf("%d ",p[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(use[i]==false && !(lv==0 && ban[i]==true))
		{
			use[i]=true;
			p[lv]=i;
			gen(lv+1);
			use[i]=false;
		}
	}
}
