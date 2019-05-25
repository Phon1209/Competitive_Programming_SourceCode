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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
map<string,int> mp;
map<int,string> rmp;
stack<int> st;
bitset<30> bt,bt2;
int rt;
vi v[30],v2[30];
void dfs(int u)
{
	bt[u]=1;
	for(int i=0;i<v[u].size();i++)
	{
		if(bt[v[u][i]]==0)
		{
			dfs(v[u][i]);
		}
	}
	st.push(u);
}
void rdfs(int u)
{
	bt2[u]=1;
	for(int i=0;i<v2[u].size();i++)
	{
		if(bt2[v2[u][i]]==0)
		{
			rdfs(v2[u][i]);
		}
	}
	if(rt==u)
		return;
	printf(", %s",rmp[u].c_str());
}
int main()
{
	int t=1;
//	freopen("uva.txt","w",stdout);
	while(1)
	{
		sint2(n,m);
		bt.reset();
		bt2.reset();
		mp.clear();
		rmp.clear();
		int cnt=0;
		if(n==0 && m==0)
		{
			break;
		}
		if(t!=1)
			printf("\n");
		for(int i=0;i<m;i++)
		{
			sstring(a,30);
			sstring(b,30);
			if(mp.find(a)==mp.end())
			{
				mp[a]=cnt;
				rmp[cnt++]=a;
			}
			if(mp.find(b)==mp.end())
			{
				mp[b]=cnt;
				rmp[cnt++]=b;
			}
			int x=mp[a],y=mp[b];
			v[x].pb(y);
			v2[y].pb(x);
		}
		for(int i=0;i<n;i++)
		{
			if(bt[i]==0)
			{
				dfs(i);
			}
		}
		printf("Calling circles for data set %d:\n",t++);
		while(!st.empty())
		{
			int tmp=st.top();
			st.pop();
			if(bt2[tmp]==0)
			{
				printf("%s",rmp[tmp].c_str());
				rt=tmp;
				rdfs(tmp);
				printf("\n");
			}
		}
		for(int i=0;i<n;i++)
		{
			v[i].clear();
			v2[i].clear();
		}
	}
}


