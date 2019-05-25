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
int a[300][300];
int chk(int x,int y)
{
	int ret=0;
	if(x&1)
	{
		if(y&1) ret|=(1<<2);
		if(y&2)	ret|=(1<<1);
		if(y&4) ret|=(1<<0);
	}
	if(x&2)
	{
		if(y&1) ret|=(1<<2);
		if(y&2)	ret|=(1<<1);
		if(y&4) ret|=(1<<1);
	}
	if(x&4)
	{
		if(y&1) ret|=(1<<1);
		if(y&2)	ret|=(1<<2);
		if(y&4) ret|=(1<<1);
	}
	return ret;
}
int h(int u,int v)
{
	if(a[u][v]!=0)
	{
		return a[u][v];
	}
//	printf("%d %d\n",u,v);
	for(int i=u;i<v;i++)
	{
		a[u][v]|=chk(h(u,i),h(i+1,v)); //split
	}
//	pause;
	return a[u][v];
}
int main()
{
	int t=20;
	while(t--)
	{
		sint(n);
		sstring(s,300);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				a[i][j]=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0') a[i][i]=1;
			if(s[i]=='1') a[i][i]=2;
			if(s[i]=='2') a[i][i]=4;
		}
		h(1,n-1);
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		*/
		if(a[1][n-1]&4 && s[0]=='0')
		{
			printf("yes\n");
		}
		else
			printf("no\n");
	}
}


