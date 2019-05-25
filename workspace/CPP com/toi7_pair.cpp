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
vi g,tmp;
long long inv=0;
long long mergesort(int st,int ed)
{
	if(st==ed)
		return g[st];
	int md=(st+ed)/2;
	long long pop=mergesort(st,md);
	mergesort(md+1,ed);
	int cnt=st,i,j;
//	printf(">>%lld\n",pop);
	for(i=st,j=md+1;i<=md && j<=ed;)
	{
		if(g[i]<=g[j])
		{
//			printf("A\n");
			tmp[cnt]=g[i];
			pop-=g[i];
			i++;
		}
		else 
		{
//			printf("B\n");
			tmp[cnt]=g[j];
			inv+=(md-i+1)*g[j];
//			printf("%d %lld %d\n",md-i+1,pop,g[j]);
			j++;
			inv+=pop;
			//cnt inv;
		}
		cnt++;
	}
	for(;i<=md;i++)
	{
		tmp[cnt]=g[i];
		cnt++;
	}
	for(;j<=ed;j++)
	{
		tmp[cnt]=g[j];
		cnt++;
	}
	pop=0;
	for(i=st;i<=ed;i++)
	{
		g[i]=tmp[i];
		pop+=tmp[i];
	}
//	printf(">>>%lld\n",pop);
	return pop;
}
int main()
{
	sint(n);
	for(int i=0;i<n;i++)
	{
		sint2(x,y);
		v.pb(mkp(y,x));
	}
	sort(all(v));
	for(int i=0;i<n;i++)
	{
		g.pb(v[i].S);
//		printf("%d ",g[i]);
	}
//	printf("\n");
	tmp.resize(g.size());
	mergesort(0,n-1);
	printf("%lld\n",inv);
}

