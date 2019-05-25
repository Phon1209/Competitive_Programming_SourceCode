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
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define sstring(a,x) char a[x]; scanf("%s",a);
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#define debug(x) cout<< #x << " = " << x;endl;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
ll a[100005];
vi g[100005];
vi v[100005];
ll dp[100005];
bool chk[100005];
ll ans=0;
void dfs(int u)
{
    chk[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int y=g[u][i];
        if(chk[y])continue;
        v[u].pb(y);
        dfs(y);
    }
}
void toa(int u)
{
    if(v[u].size()==0)
    {
        dp[u]=a[1];
        return ;
    }
    dp[u]=0;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        toa(y);
        dp[u]+=dp[y];
        ans=max(ans,dp[u]+a[i+1]);
    }
    if(u!=1)
        dp[u]+=a[v[u].size()+1];
    else
        dp[u]+=a[v[u].size()];
    ans=max(ans,dp[u]);
}
int main()
{
    sint(n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<n;i++)
    {
        sint2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }
    ans=a[0];
    dfs(1);
    toa(1);
    printf("%lld\n",ans);
}
/*
2
-10 -3
1 2


*/
