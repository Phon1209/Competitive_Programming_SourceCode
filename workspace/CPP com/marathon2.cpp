#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define sstring(a,x) char a[x]; scanf("%s",a);
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int a[505][505];
int main()
{
	sint2(n,m);
	vii v;
	for(int i=0;i<n;i++)
	{
		sint2(x,y);
		v.pb(mkp(x,y));
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			a[i][j]=inf;
		}
	}
	a[0][0]=0;
	for(int i=1;i<n;i++)
	{
		int w;
		w=abs(v[i].F-v[i-1].F)+abs(v[i].S-v[i-1].S);
		a[i][0]=a[i-1][0]+w;
		for(int j=1;j<=m;j++)
		{
			if(j>i)
				continue;
			int w2=inf;
			for(int k=0;k<=j;k++)
			{
				if(i-k-1<0)
					continue;
				if(j-k<0)
					continue;
				int tmp;
				tmp=abs(v[i].F-v[i-k-1].F)+abs(v[i].S-v[i-k-1].S);
				w2=min(w2,tmp+a[i-k-1][j-k]);
			}
			a[i][j]=w2;
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			printf("%d ",a[i][j]);
		}
		endl;
	}
	//*/
	int ans=inf;
	for(int i=0;i<=m;i++)
	{
		ans=min(ans,a[n-1][i]);
	}
	printf("%d\n",ans);
}


