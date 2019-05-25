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
vii p;
int cnt=0;
int a[505][505];
class UnionFind
{
	public:
		UnionFind(int n)
		{
			p.assign(n,mkp(0,0));
			for(int i=0;i<n;i++)
			{
				p[i]=mkp(i,-1);
			}
		}
		ii fs(int i)
		{
			return(p[i].F==i)? mkp(i,p[i].S):(p[i]=fs(p[i].F));
		}
		bool iss(int i,int j)
		{
			ii x,y;
			x=fs(i);
			y=fs(j);
//			printf(">%d %d\n",x.F,y.F);
			return (x.F==y.F);
		}
		void us(int i,int j)
		{
			ii x,y;
			x=fs(i);
			y=fs(j);
			p[x.F].F=y.F;
//			printf("\n%d %d\n",x.S,y.S);
			if(x.S!=-1 && y.S!=-1)
			{
				cnt--;
			}
			p[x.F].S=max(x.S,y.S);
			p[y.F].S=max(x.S,y.S);
		}
};
int main()
{
	sint2(n,m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	UnionFind uf(n*m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sint(h);
			if(h==1)
			{
				int tmp;
				tmp=(i*m);
				tmp+=j;
				p[tmp].S=++cnt;
			}
		}
	}
	vector<pair<int,ii> > v;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int tmp,tmp2;
			tmp=i*m;
			tmp+=j;
			if(j!=m-1)
			{
				tmp2=i*m;
				tmp2+=j+1;
				v.pb(mkp(abs(a[i][j]-a[i][j+1]),mkp(tmp,tmp2)));
			}
			if(i!=n-1)
			{
				tmp2=(i+1)*m;
				tmp2+=j;
				v.pb(mkp(abs(a[i][j]-a[i+1][j]),mkp(tmp,tmp2)));
			}
		}
	}
	sort(all(v));
	int ans=0;
	for(int i=0;i<v.size();i++)
	{
		int w;
		int x,y;
		w=v[i].F;
		x=v[i].S.F;
		y=v[i].S.S;
		if(cnt==1)
		{
			break;
		}
		if(!uf.iss(x,y))
		{
			uf.us(x,y);
			ans=max(ans,w);
		}
	}
	printf("%d\n",ans);
}


