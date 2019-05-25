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
int a[6005];
int b[6005][5];
vi v[6005];
ii dfs(int u)
{
	if(v[u].size()==0)
	{
		b[u][0]=max(0,a[u]);
		b[u][1]=0;
		return mkp(max(0,a[u]),0);
	}
	int cnt=0,cnt2=0;
	for(int i=0;i<v[u].size();i++)
	{
		ii p=dfs(v[u][i]);
		cnt2+=max(p.F,p.S);
		cnt+=p.S;
	}
	cnt+=a[u];
	b[u][0]=cnt;
	b[u][1]=cnt2;
	return mkp(cnt,cnt2);
}
bitset<6005> bt;
int main()
{
	sint(n);
	for(int i=1;i<=n;i++)
	{
		int1(a[i]);
	}
	while(1)
	{
		sint2(x,y);
		if(x==0 && y==0) break;
		v[y].pb(x);
		bt[x]=1;
	}
	int root;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!bt[i])
		{
			root=i;
			dfs(root);
			ans+=max(b[root][0],b[root][1]);
		}
	/*
	for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",b[i][0],b[i][1]);
	}
	*/
	printf("%d\n",ans);
}


