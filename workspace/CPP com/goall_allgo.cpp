#include<bits/stdc++.h>
char c[55];
int a[55][55];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",c);
			for(int j=0;j<n;j++)
			{
				if(c[j]=='0')
				{
					a[i][j]=0;
				}
				else
				{
					a[i][j]=1;
				}
			}
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(a[i][k]==1 && a[k][j]==1)
					{
						a[i][j]=1;
					}
				}
			}
		}
		int chk1=0,chk2=0,chk=0;
		for(int i=0;i<n;i++)
		{
			chk=0;
			for(int j=0;j<n;j++)
			{
				if(i==j || a[i][j])
				{
					chk++;
				}
			}
			if(chk==n)
			{
				chk1++;
			}
			chk=0;
			for(int j=0;j<n;j++)
			{
				if(i==j || a[j][i])
				{
					chk++;
				}
			}
			if(chk==n)
			{
				chk2++;
			}
		}
		printf("%d %d\n",chk1,chk2);
	}
}
