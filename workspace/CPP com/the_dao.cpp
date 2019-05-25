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
class UnionFind
{
	private:
		vi p;
	public:
		UnionFind(int n)
		{
			p.assign(n,0);
			for(int i=0;i<n;i++)
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
};
int main()
{
	sint(n);
	vi r;
	for(int i=0;i<n;i++)
	{
		sint(x);
		r.pb(x);
	}
	vector<pair<int,ii> > v;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int tmp;
			tmp=r[i]^r[j];
			v.pb(mkp(tmp,mkp(i,j)));
		}
	}
	sort(all(v));
	UnionFind uf(n);
	long long ans=0;
	int cmp=n;
	for(int i=v.size()-1;i>=0;i--)
	{
		if(!uf.iss(v[i].S.F,v[i].S.S))
		{
			cmp--;
			uf.us(v[i].S.F,v[i].S.S);
			ans+=v[i].F;
		}
		if(cmp==1)
			break;
	}
	printf("%lld\n",ans);
}


