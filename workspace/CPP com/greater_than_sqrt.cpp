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
vi v;
int T;
multiset<int> ms[500];
multiset<int>::iterator it;
int a[500][500];
void upt(int idx,int val)
{
	int x,y;
	x=idx/T;
	y=idx%T;
	int tmp;
	tmp=a[x][y];
	a[x][y]=val;
	it=ms[x].find(tmp);
	ms[x].erase(it);
	ms[x].insert(val);
}
int find(int x,int y,int k)
{
	int ret=inf;
	for(int i=0;i<T;i++)
	{
		int l,r;
		l=i*T;
		r=(i*T)+T-1;
//		printf("%d %d %d\n",i,l,r);
		if(r<x || y<l) continue;
		if(x<=l && r<=y)
		{
//			printf("A\n");
			it=ms[i].upper_bound(k);
			if(it!=ms[i].end())
				ret=min(ret,(*it));
		}
		if(x<=l && y<r)
		{
//			printf("B\n");
			for(int j=0;j<=y%T;j++)
			{
				if(a[i][j]>k) ret=min(ret,a[i][j]);
			}
		}
		if(l<x && y>=r)
		{
//			printf("C\n");
			for(int j=x%T;j<T;j++)
			{
				if(a[i][j]>k) ret=min(ret,a[i][j]);
			}
		}
		if(l<x && y<r)
		{
//			printf("D\n");
			for(int j=x%T;j<=y%T;j++)
			{
				if(a[i][j]>k) ret=min(ret,a[i][j]);
			}
		}
	}
	return ret;
}
int main()
{
	sint2(n,m);
	T=sqrt(n)+1;
	for(int i=0;i<n;i++)
	{
		sint(tmp);
		int x,y;
		x=i/T;
		y=i%T;
		ms[x].insert(tmp);
		a[x][y]=tmp;
	}
	while(m--)
	{
		char c[5];
		/*
		for(int i=0;i<T;i++)
		{
			it=ms[i].begin();
			while(it!=ms[i].end())
			{
				printf("%d ",(*it));
				it++;
			}
			printf("\t");
			for(int j=0;j<T;j++)
			{
				printf("%d ",a[i][j]);
			}
			endl;
		}
		*/
		scanf("%s",c);
		if(c[0]=='q')
		{
			sint3(x,y,k);
			x--;
			y--;
			int tmp=find(x,y,k);
			if(tmp!=inf)
				printf("%d\n",tmp);
			else
				printf("no\n");
		}
		else if(c[0]=='c')
		{
			sint2(idx,val);
			idx--;
			upt(idx,val);
		}
	}
}

