#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int a[400][400];
int main()
{
	sint(t);
	while(t--)
	{
		sint2(n,m);
		sint2(ok,p);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				a[i][j]=1;
			}
		}
		for(int i=0;i<p;i++)
		{
			sint2(x,y);
			a[x][y]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]+=a[i][j-1];
			}
		}
		bool chk=false;
		for(int i=1;i<=m;i++)
		{
			for(int j=i;j<=m;j++)
			{
				int mx=0,cnt=0;
				for(int k=1;k<=n;k++)
				{
					if(a[k][j]-a[k][i-1]==(j-i+1))
					{
						cnt+=(j-i+1);
						mx=max(mx,cnt);
					}
					else
					{
						cnt=0;
					}
				}
				if(mx>=ok)
				{
					chk=true;
				}
			}
		}
		if(chk)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
}

