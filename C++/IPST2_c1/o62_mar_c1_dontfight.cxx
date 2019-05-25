#include<bits/stdc++.h>
using namespace std;
#define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; qread(a);
#define sint2(a,b) int a,b; qread(a),qread(b);
#define sint3(a,b,c) int a,b,c; qread(a),qread(b),qread(c);
#define int1(a) qread(a);
#define int2(a,b) qread(a),qread(b);
#define int3(a,b,c) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define cstring(a,x) char a[x]; scanf("%s",a);
#define sstring(a) string a;cin>>a;
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug(x)
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
#endif
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void qread(int &x){
	int neg=1;x=0;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}
vi v[300005];
ll a[300005];
ll dp[300005];
ll test=0;
int cnt=0;
ll mn=-1,mx=-1;
void update(ll x)
{
    if(mn==-1)mn=x;
    else mn=min(mn,x);
    if(mx==-1)mx=x;
    else mx=max(mx,x);
}
void dfs(int u,int p=0)
{
    dp[u]=a[u];
    int mem=0;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(y==p)continue;
        dfs(y,u);
        debug(y);
        debug(dp[y]);
        dp[u]+=dp[y];
        if(dp[y]>=test)
        {
            mem=y;
        }
    }
    debug(u);
    debug(cnt);
    if(mem!=0)
    {
        cnt++;
        debug(((((dp[mem])))));
        update(dp[mem]);
        dp[u]-=dp[mem];
    }
    if(dp[u]>=test){
        debug(((((((dp[u])))))));
        update(dp[u]);
        dp[u]=0;
        cnt++;
    }
	// if(u==1 && dp[u]!=0)
	// {
	// 	update(dp[1]);
	// 	cnt++;
	// }
}
int main()
{
    sint(n);
    ll l=1,r=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        r+=a[i];
    }
    for(int i=1;i<n;i++)
    {
        sint2(x,y);
        v[x].pb(y);
        v[y].pb(x);
    }
    ll ans=LLONG_MAX;
    while(l<=r)
    {
        ll md=(l+r)/2;
        test=md;
        debug(((((((((((((((((((md)))))))))))))))))));
        mn=-1;
        mx=-1;
        memset(dp,0,sizeof(0));
        cnt=0;
        dfs(1);
        debug(cnt);
        if(cnt>3)
        {
            l=md+1;
        }
        else if(cnt<3)
        {
            r=md-1;
        }
        else if(cnt==3)
        {
			if(dp[1])
			{
				l=md+1;
				continue;
			}
            debug(((mn)));
            debug(((mx)));
            ans=min(ans,mx-mn);
            l=md+1;
        }
    }
    Wl(ans);
}
/*
12
9 10 5 9 7 6 4 3 20 1 1 1
1 2
1 3
2 4
2 5
3 9
5 6
5 7
5 8
9 10
9 11
9 12
*/
