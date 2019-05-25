#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define mkt make_tuple
#define pb push_back
#define eb emplace_back
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
#define debug(x) cout<< #x << " = " << x;endl;
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int p[100005],sum[100005];
vii edge;
ii dp[100005],dp2[100005];
vi v[100005];
void dfs(int u)
{
    int sm=1;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(y==p[u])continue;
        p[y]=u;
        dfs(y);
        sm+=sum[y];
        if(sum[y]>=dp[u].F)
        {
            swap(dp[u],dp2[u]);
            dp[u]={sum[y],y};
        }
        else if(sum[y]>=dp2[u].F)
            dp2[u]={sum[y],y};
    }
    sum[u]=sm;
}
int main()
{
    sint(n);
    for(int i=1;i<n;i++)
    {
        sint2(x,y);
        edge.eb(mkp(x,y));
        v[x].eb(y);
        v[y].eb(x);
    }
    dfs(1);
    ll ans=0;
    for(int i=0;i<edge.size();i++)
    {
        int x,y;
        x=edge[i].F;
        y=edge[i].S;
        if(p[x]==y)swap(x,y);
        int num=n-sum[x];
        if(dp[x].S==y) num=max(num,dp2[x].F);
        else           num=max(num,dp[x].F);
        ans=max(ans,(ll)num*(ll)(dp[y].F));
    }
    printf("%lld\n",ans);
}
/*

*/
