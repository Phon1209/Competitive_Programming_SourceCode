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
vector<pair<ii,ii> > v;
class UnionFind
{
	private:
		vi p;
	public:
		UnionFind(int n)
		{
			p.assign(n+1,0);
			for(int i=0;i<=n;i++)
				p[i]=i;
		}
		int fs(int i)
		{
			return (p[i]==i)? i:(p[i]=fs(p[i]));
		}
		bool iss(int i,int j)
		{
			return (fs(i)==fs(j));
		}
		void us(int i,int j)
		{
			int x,y;
			x=fs(i);
			y=fs(j);
			p[x]=y;
		}
		void reset(int n)
		{
			p.assign(n+1,0);
			for(int i=0;i<=n;i++)
				p[i]=i;
		}
};
void _main()
{
	v.clear();
	sint2(n,m);
	for(int i=0;i<m;i++)
	{
		sint3(x,y,w);
		v.pb(mkp(mkp(w,i),mkp(x,y)));
	}
	sort(all(v));
	UnionFind uf(n);
	int a1=0;
	queue<int> q;
	for(int i=0;i<v.size();i++)
	{
		int x,y;
		x=v[i].S.F;
		y=v[i].S.S;
		if(!uf.iss(x,y))
		{
			uf.us(x,y);
//			printf("%d %d\n",x,y);
			a1+=v[i].F.F;
			q.push(v[i].F.S);
		}
	}
	int a2=0,ans=inf;
	while(!q.empty())
	{
		uf.reset(n);
		a2=0;
		for(int i=0;i<v.size();i++)
		{
			int x,y;
			x=v[i].S.F;
			y=v[i].S.S;
			if(v[i].F.S==q.front())
				continue;
			if(!uf.iss(x,y))
			{
				uf.us(x,y);
				a2+=v[i].F.F;
			}
		}
//		printf("%d %d\n",a1,a2);
//		pause;
		if(a2>a1)
		{
			ans=min(a2,ans);
		}
		q.pop();
	}
	printf("%d %d\n",a1,ans);
}
int main()
{
	sint(t);
	while(t--)
		_main();
}


