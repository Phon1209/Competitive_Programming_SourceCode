#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mp make_pair
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
class UnionFind
{
	private:
		vector<int> p;
	public:
		UnionFind(int n)
		{
			p.assign(n,0);
			for(int  i=0;i<n;i++)
				p[i]=i;
		}
		bool iss(int i,int j)
		{
			return (fs(i)==fs(j));
		}
		int fs(int i)
		{
			return (p[i]==i)? i:(p[i]=fs(p[i]));
		}
		void us(int i,int j)
		{
			int x,y;
			x=fs(i);
			y=fs(j);
			p[x]=y;
		}
};
vector<pair<int,ii> > v;
int main()
{
	int g=inf;
	printf("%d\n",g);
	sint2(n,m);
	for(int i=0;i<m;i++)
	{
		sint3(s,t,w);
		v.pb(mp(w,mp(s,t)));
	}
	sort(all(v));
	UnionFind uf(n);
	long long ans=0;
	for(int i=0;i<m;i++)
	{
		if(!uf.iss(v[i].S.F,v[i].S.S))
		{
			ans+=v[i].F;
			uf.us(v[i].S.F,v[i].S.S);
		}
	}
	printf("%lld\n",ans);
}
