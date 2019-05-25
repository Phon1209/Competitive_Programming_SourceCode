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

vi v[35][2]; // Problem Win/Lose
vi g[100005],g2[100005];
map<ii,bool> h;
bitset<100005> vs;
stack<int> st;
int group[100005];
void dfs(int u)
{
    vs[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int y=g[u][i];
        if(vs[y])continue;
        dfs(y);
    }
    // printf("Push %d to stack\n",u);
    st.push(u);
}
static int Q=0;
void dfs2(int u)
{
    group[u]=Q;
    vs[u]=1;
    // printf("%d in group %d\n",u,Q);
    for(int i=0;i<g2[u].size();i++)
    {
        int y=g2[u][i];
        if(vs[y])continue;
        dfs2(y);
    }
}
vii edge;
bitset<100005> in;
int main()
{
    sint2(n,k);
    for(int i=1;i<=n;i++)
    {
        sstring(s);
        for(int j=0;j<s.size();j++)
        {
            v[j][s[j]-'0'].pb(i);
        }
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<v[i][1].size();j++)
        {
            for(int l=0;l<v[i][0].size();l++)
            {
                if(h.find(mkp(v[i][1][j],v[i][0][l]))!=h.end())continue;
                h[mkp(v[i][1][j],v[i][0][l])]=1;
                edge.pb(v[i][1][j],v[i][0][l]);
                g[v[i][1][j]].pb(v[i][0][l]);
                g2[v[i][0][l]].pb(v[i][1][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vs[i])
            dfs(i);
    }
    vs.reset();
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!vs[u])
        {
            Q++;
            dfs2(u);
        }
    }

    for(int i=0;i<edge.size();i++)
    {
        int x,y;
        x=edge[i].F;
        y=edge[i].S;
        if(group[x]!=group[y])
            in[group[y]]=1/*,printf("Kill Group %d\n",group[y])*/;
    }
    int r=-1;
    for(int i=1;i<=Q;i++)
    {
        if(in[i]==0)
        {
            if(r==-1)
                r=i;
            else
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(group[i]==r)W(i);
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
