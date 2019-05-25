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
#define MOD 1000000007
//#pragma GCC optimize ("O3")
//state town stay day all?
vi v[5];
int a[5],n;
int dp[5][1005][1005][10];
int find(int tw,int st,int day,int ok)
{
//	printf("%d %d %d %d\n",tw,st,day,ok);
	if(day==n)
	{
		if(ok==7) return 1;
		return 0;
	}
	if(dp[tw][st][day][ok]) return dp[tw][st][day][ok];
	dp[tw][st][day][ok]=0;
	for(int i=0;i<v[tw].size();i++)
	{
		int to=v[tw][i];
		dp[tw][st][day][ok]+=find(to,1,day+1,ok|(1<<to));
		dp[tw][st][day][ok]%=MOD;
	}
	if(st<a[tw])
	{
		dp[tw][st][day][ok]+=find(tw,st+1,day+1,ok);
		dp[tw][st][day][ok]%=MOD;
	}
	return dp[tw][st][day][ok];
}
int main()
{
	v[0].pb(1);
	v[1].pb(2);
	v[0].pb(2);
	v[2].pb(0);
	int1(n);
	int3(a[0],a[1],a[2]);
	printf("%d\n",find(0,1,1,1)%MOD);
}
