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
int a[1005][1005];
int g[1005];
int n,k;
bool ok=0;
void find(int lv,int dis)
{
	if(ok)return;
	if(lv==k-1)
	{
		ok=1;
		for(int i=0;i<k;i++)
		{
			printf("%d\n",g[i]);
		}
		return;
	}
	int tmp;
	bool use;
	use=1;
	tmp=dis+a[lv][lv+1];
	if(tmp>=n) tmp-=n;
	if(tmp<0 ) tmp+=n;
	g[lv+1]=tmp;
	for(int i=lv;i>=0;i--)
	{
		if(n-abs(g[lv+1]-g[i])!=a[i][lv+1] && abs(g[lv+1]-g[i])!=a[i][lv+1])
		{
			use=0;
		}
	}
	if(use) find(lv+1,g[lv+1]); 
	if(ok)return;
	use=1;
	tmp=dis-a[lv][lv+1];
	if(tmp>=n) tmp-=n;
	if(tmp<0 ) tmp+=n;
	g[lv+1]=tmp;
	for(int i=lv;i>=0;i--)
	{
		if(n-abs(g[lv+1]-g[i])!=a[i][lv+1] && abs(g[lv+1]-g[i])!=a[i][lv+1])
		{
			use=0;
		}
	}
	if(use) find(lv+1,g[lv+1]);
}
int main()
{
	int2(n,k);
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			int1(a[i][j]);
		}
	}
	g[0]=0;
	find(0,0);
}

