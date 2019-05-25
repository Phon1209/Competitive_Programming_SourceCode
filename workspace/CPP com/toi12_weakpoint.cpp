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
#define MAX_N 500005
vi v[MAX_N];
int p[MAX_N];
int c[MAX_N];
int idx=0;
bool ok[MAX_N];
int main()
{
	sint2(n,k);
	for(int i=0;i<n;i++)
	{
		sint2(x,y);
		v[x].pb(y);
		v[y].pb(x);
	}
	ok[k]=1;
	queue<int> q;
	bool chk=0;
	for(int i=0;i<v[k].size();i++)
	{
		int u=v[k][i];
		q.push(u);
		p[u]=k;
		while(!q.empty())
		{
			int uu=q.front();
//			printf("%d\n",uu);
			q.pop();
			bool found=0;
			for(int j=0;j<v[uu].size();j++)
			{
				int o=v[uu][j];
				if(o==p[uu]) continue;
				if(o==k)
				{
					found=1;
					break;
				}
				p[o]=uu;
				q.push(o);
			}
			if(found)
			{
				chk=1;
				while(uu!=u)
				{
					c[idx++]=uu;
					ok[uu]=1;
					uu=p[uu];
				}
				ok[u]=1;
				c[idx++]=u;
				break;
			}
		}
		if(chk) break;
	}
//	printf("B\n");
	for(int i=0;i<v[k].size();i++)
	{
		int u=v[k][i];
		if(ok[u]) continue;
		ok[u]=1;
		c[idx++]=u;
	}
	int ans=0,ans2=1e9;
	while(!q.empty()) q.pop();
//	printf("A\n");
	for(int i=0;i<idx;i++)
	{
		int u=c[i];
		q.push(u);
		int cnt=-1;
		while(!q.empty())
		{
			int uu=q.front();
//			printf("%d\n",uu);
			cnt++;
			q.pop();
			for(int j=0;j<v[uu].size();j++)
			{
				int o=v[uu][j];
				if(ok[o]) continue;
				ok[o]=1;
				q.push(o);
			}
		}
		if(cnt==ans && u<ans2)
		{
			ans2=u;
		}
		if(cnt>ans)
		{
			ans=cnt;
			ans2=u;
		}
	}
	printf("%d\n%d\n",ans2,ans);
}


