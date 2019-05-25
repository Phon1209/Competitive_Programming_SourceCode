#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
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
multiset<int> s[200005];
map<int,int> mp;
int r[200005];
int a[100005];
int b[100005];
vector<bool> visit;
int w=0;
void dfs(int u)
{
    visit[u]=1,w++;
    for(int y:s[u])if(!visit[y])dfs(y);
}
vi step;
void euler(int u)
{
    // debug(u);
    while(!s[u].empty())
    {
        int y=*(s[u].begin());
        s[u].erase(s[u].begin());
        s[y].erase(s[y].find(u));
        euler(y);
    }
    step.pb(u);
}
int main()
{
    sint(n);
    for(int i=1;i<n;i++)
    {
        int1(a[i]);
        mp[a[i]];
    }
    for(int i=1;i<n;i++)
    {
        int1(b[i]);
        mp[b[i]];
    }
    int cnt=0;
    for(auto it: mp)
    {
        mp[it.F]=++cnt;
        r[cnt]=it.F;
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        x=mp[a[i]];
        y=mp[b[i]];
        if(a[i]>b[i])
        {
            printf("-1\n");
            return 0;
        }
        s[x].emplace(y);
        s[y].emplace(x);
        // W(x);Wl(y);
    }
    n=mp.size();
    visit.assign(n+5,false);
    dfs(1);
    // debug(5);
    if(w!=n)
    {
        printf("-1\n");
        return 0;
    }
    debug(60)
    int odd=0;
    int st=1;
    for(int i=1;i<=n;i++)
        if(s[i].size()&1)odd++,st=i;
    if(odd>2)
    {
        printf("-1\n");
        return 0;
    }
    debug(7)
    euler(st);
    for(int i=0;i<step.size();i++)
    {
        W(r[step[i]]);
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
