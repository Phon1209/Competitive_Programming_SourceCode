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
vii v;
int lim;
int a[1<<17][20];
int f(int e,int u)
{
//	printf("%d %d\n",e,u);
	if(e==lim)
	{
		int s=abs(v[u].F-v[0].F)+abs(v[u].S-v[0].S);
		a[e][u]=s;
//		printf("A %d %d %d\n",e,u,a[e][u]);
		return s;
	}
	if(a[e][u]!=inf)
	{
		return a[e][u];
	}
	for(int i=1;i<v.size();i++)
	{
		int tmp=e;
		if((tmp|=(1<<i))!=e)
		{
			int s=abs(v[u].F-v[i].F)+abs(v[u].S-v[i].S);
			a[e][u]=min(a[e][u],f(tmp,i)+s);
		}
	}
//	printf("%d %d %d\n",e,u,a[e][u]);
	return a[e][u];
//	system("pause");
}
int main()
{
	sint2(d,r);
	sint(n);
	v.pb(mkp(d,r));
	lim=(1<<(n+1))-1;
	for(int i=0;i<(1<<17);i++)
	{
		for(int j=0;j<17;j++)
		{
			a[i][j]=inf;
		}
	}
//	printf("%d\n",lim);
	for(int i=0;i<n;i++)
	{
		sint2(x,y);
		v.pb(mkp(x,y));
	}
	f(1,0);
	printf("%d\n",a[1][0]);
}

