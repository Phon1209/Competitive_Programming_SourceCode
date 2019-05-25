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
int sg[400][20005];
int lz[400][20005];
int n,m,k;
void build(int idx,int x,int l,int r)
{
//	printf("%d %d %d %d\n",idx,x,l,r);
	lz[x][idx]=-1;
	if(l==r)
	{
		if(l<=m)
			sg[x][idx]=0;
		else
			sg[x][idx]=1e9+5;
		return;
	}
	int md=(l+r)/2;
	build(idx*2,x,l,md);
	build(idx*2+1,x,md+1,r);
	sg[x][idx]=min(sg[x][idx*2],sg[x][idx*2+1]);
}
void uptlz(int idx,int x,int l,int r,int val)
{
	lz[x][idx]=val;
	sg[x][idx]=val;
}
void shift(int idx,int x,int l,int r)
{
	if(lz[x][idx]==-1) return;
	int md=(l+r)/2;
	uptlz(idx*2,x,l,md,lz[x][idx]);
	uptlz(idx*2+1,x,md+1,r,lz[x][idx]);
	lz[x][idx]=-1;
}
void uptrw(int x,int val)
{
	sg[x][1]=val;
	lz[x][1]=val;
}
void upt(int idx,int l,int r,int x,int pos,int val)
{
//	printf("%d %d %d %d %d %d\n",idx,l,r,x,pos,val);
	if(l==r)
	{
		sg[x][idx]=val;
		return;
	}
	int md=(l+r)/2;
	shift(idx,x,l,r);
	if(pos<=md)
	{
		upt(idx*2,l,md,x,pos,val);
		sg[x][idx]=min(sg[x][idx*2],sg[x][idx*2+1]);
		return;
	}
	upt(idx*2+1,md+1,r,x,pos,val);
	sg[x][idx]=min(sg[x][idx*2],sg[x][idx*2+1]);
}
int query(int idx,int x,int l,int r,int pos)
{
//	printf("%d %d %d %d %d\n",idx,l,r,x,pos);
	if(l==r)
	{
		return sg[x][idx];
	}
	int md=(l+r)/2;
	shift(idx,x,l,r);
	if(pos<=md)
	{
		return query(idx*2,x,l,md,pos);
	}
	return query(idx*2+1,x,md+1,r,pos);
}
int main()
{
	int3(n,m,k);
	for(int i=1;i<=n;i++)
	{
		build(1,i,1,m);
	}
	while(k--)
	{
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=2*m+1;j++)
			{
				printf("%d ",sg[i][j]);
			}
			endl;
		}
		//*/
		sint(cm);
		if(cm==1)
		{
			sint3(x,y,val);
			upt(1,1,m,x,y,val);
		}
		if(cm==2)
		{
			sint2(x,val);
			uptrw(x,val);
		}
		if(cm==3)
		{
			sint2(x,y);
			printf("%d\n",query(1,x,1,m,y));
		}
		if(cm==4)
		{
			int ret=1e9;
			for(int i=1;i<=n;i++)
			{
				ret=min(ret,sg[i][1]);
			}
			printf("%d\n",ret);
		}
	}
}

