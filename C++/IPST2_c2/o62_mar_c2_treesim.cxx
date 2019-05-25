#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
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
vi v[200005],v2[200005];
const ll hsh1=13;
const ll hsh2=19;
const ll hsh3=97;
tuple<ll,ll,ll> H[200005],maxx;
set<tuple<ll,ll,ll> > hsh;
int deg[200005];
vi leaf;
ll expo(ll a,int b)
{
    if(b==1)return a;
    ll p=expo(a,b/2);
    p*=p;
    p*=((b%2)? a:1);
    return p;
}
int ans=0;
int dfs(int u,int p)
{
    int sz;
    if(deg[u]==1)H[u]=mkt(expo(hsh1,u),expo(hsh2,u),expo(hsh3,u)),sz=1;
    else H[u]=mkt(0,0,0),sz=0;
    debug(u);
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(y==p)continue;
        sz+=dfs(y,u);
        get<0>(H[u])+=get<0>(H[y]);
        get<1>(H[u])+=get<1>(H[y]);
        get<2>(H[u])+=get<2>(H[y]);
    }
    debug(1);
    if(u==1)
    {
        return sz;
    }
    if(sz>(int)(leaf.size()/2))
    {
        debug(12);
        hsh.insert(mkt(get<0>(maxx)-get<0>(H[u]),get<1>(maxx)-get<1>(H[u]),get<2>(maxx)-get<2>(H[u])));
        // printf("Insert %lld %lld %lld\n",get<0>(maxx)-get<0>(H[u]),get<1>(maxx)-get<1>(H[u]),get<2>(maxx)-get<2>(H[u]));
    }
    else
    {
        debug(6);
        hsh.insert(H[u]);
        ll x,y,z;
        tie(x,y,z)=H[u];
        // printf("Insert %lld %lld %lld\n",x,y,z);
    }
    // ll x,y,z;
    // tie(x,y,z)=H[u];
    // printf("hsh for %d is %lld %lld %lld\n",u,x,y,z);
    return sz;
    // debug(u);
}
int dfs2(int u,int p)
{
    int sz;
    if(deg[u]==1)H[u]=mkt(expo(hsh1,u),expo(hsh2,u),expo(hsh3,u)),sz=1;
    else H[u]=mkt(0,0,0),sz=0;
    debug(u);
    for(int i=0;i<v2[u].size();i++)
    {
        int y=v2[u][i];
        if(y==p)continue;
        sz+=dfs2(y,u);
        get<0>(H[u])+=get<0>(H[y]);
        get<1>(H[u])+=get<1>(H[y]);
        get<2>(H[u])+=get<2>(H[y]);
    }
    debug(1);
    if(u==1)
    {
        return sz;
    }
    if(sz>(int)(leaf.size()/2))
    {
        debug(12);
        if(hsh.empty() || hsh.find(mkt(get<0>(maxx)-get<0>(H[u]),get<1>(maxx)-get<1>(H[u]),get<2>(maxx)-get<2>(H[u])))==hsh.end())
        {
            ans++;
        }
        // printf("Search %lld %lld %lld\n",get<0>(maxx)-get<0>(H[u]),get<1>(maxx)-get<1>(H[u]),get<2>(maxx)-get<2>(H[u]));
    }
    else
    {
        debug(6);
        if(hsh.empty() || hsh.find(H[u])==hsh.end())
        {
            ans++;
        }
        ll x,y,z;
        tie(x,y,z)=H[u];
        // printf("Search %lld %lld %lld\n",x,y,z);
    }
    return sz;
    // ll x,y,z;
    // tie(x,y,z)=H[u];
    // printf("hsh for %d is %lld %lld %lld\n",u,x,y,z);
    // return sz;
    // debug(u);
}
int main()
{
    sint(n);
    // debug(2);
    for(int i=0;i<2*n-3;i++)
    {
        sint2(x,y);
        v[x].pb(y);
        v[y].pb(x);
        deg[x]++;
        deg[y]++;
    }
    // debug(1);
    ll x=0,y=0,z=0;
    for(int i=1;i<=2*n-2;i++)
    {
        // debug(4);
        if(deg[i]==1)
        {
            leaf.pb(i);
            // debug(expo(hsh1,i));
            x+=expo(hsh1,i);
            // debug(x);
            y+=expo(hsh2,i);
            // debug(y);
            z+=expo(hsh3,i);
            // debug(z);
        }
    }
    maxx=mkt(x,y,z);
    for(int i=0;i<2*n-3;i++)
    {
        sint2(x,y);
        v2[x].pb(y);
        v2[y].pb(x);
    }
    dfs(1,-1);
    // for(int i=0;i<=2*n-2;i++)H[i]=mkt(0,0,0);
    dfs2(1,-1);
    Wl(ans);
}
/*
5
1 8
2 6
3 6
6 8
8 7
7 4
5 7

1 8
8 5
7 8
2 6
6 3
4 7
6 7
*/
