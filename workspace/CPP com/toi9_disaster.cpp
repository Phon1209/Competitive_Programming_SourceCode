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
multiset<int> ms[30];
stack<int> st;
int a[30];
int f(char c)
{
	return c-'A';
}
void dfs(int u)
{
//	printf("%d\n",u);
	while(!ms[u].empty())
	{
		int tmp=(*ms[u].begin());
		ms[tmp].erase(u);
		ms[u].erase(tmp);
		dfs(tmp);
	}
	st.push(u);
}
int main()
{
	sint(n);
	FOR(i,0,n)
	{
		sstring(s,5);
		int tmp=f(s[0]),tmp2=f(s[1]);
//		printf("%d %d\n",tmp,tmp2);
		ms[tmp].insert(tmp2);
		ms[tmp2].insert(tmp);
		a[tmp]++;
		a[tmp2]++;
	}
	bool chk=false,k;
	for(int i=0;i<26;i++)
	{
		if(a[i]%2)
		{
			dfs(i);
			chk=true;
			break;
		}
		if(a[i]!=0)
			k=i;
	}
	if(!chk)
		dfs(k);
	while(!st.empty())
	{
		printf("%c ",st.top()+'A');
		st.pop();
	}
	printf("\n");
}


